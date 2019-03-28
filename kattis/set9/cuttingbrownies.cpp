/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		int b, d;
		cin>>b>>d;
		string s;
		cin>>s;
		bool horizontal = false;
		if (s[0] == 'H') horizontal = true;
		vpi choco;
		choco.pb({ b, d});
		string loser;
		while (true) {
			if (horizontal) {
				int cur = INF;
				int idx = -1;
				forn(i,0,sz(choco)-1)
					if (choco[i].nd > 1 && choco[i].st >= 1 && choco[i].st < cur) {
						cur = choco[i].st;
						idx = i;
					}
				// debug(cur);
				if (cur == INF) {
					loser = "Harry";
					break;
				}
				int ini = choco[idx].nd;
				choco[idx].nd = ini/2;
				choco.pb({choco[idx].st, ini - choco[idx].nd});

			} else {
				int cur = INF;
				int idx = -1;
				forn(i,0,sz(choco)-1)
					if (choco[i].st > 1 && choco[i].nd >= 1 && choco[i].nd < cur) {
						cur = choco[i].nd;
						idx = i;
					}
				// debug(cur);
				if (cur == INF) {
					loser = "Vicky";
					break;
				}
				int ini = choco[idx].st;
				choco[idx].st = ini/2;
				choco.pb({ini - choco[idx].st, choco[idx].nd});
			}
			horizontal = !horizontal;
		}
		if (s == loser) cout << s << " cannot win\n";
		else cout << s << " can win\n";
	}
	return 0;
}
