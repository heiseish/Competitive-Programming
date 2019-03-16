/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
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
	string s;
	cin>>s;
	int rank  = 25;
	int star = 0;
	vi maxstar(26);
	forn(i,21,25) maxstar[i] = 2;
	forn(i,16,20) maxstar[i] = 3;
	forn(i,11,15) maxstar[i] = 4;
	forn(i,1,10) maxstar[i] = 5;
	int consewin = 0;
	for (auto &v : s) {
		if (rank == 0) break;
		if (v == 'W') {
			if (consewin >= 2 && rank >= 6 && rank <= 25) star+=2;
			else star++;
			consewin++;
			if (rank > 0 && star > maxstar[rank]) star -= maxstar[rank--];
		} else {
			consewin = 0;
			if (rank >= 1 && rank <= 20) star--;
			if (star < 0) {
				if (rank < 20) {
					rank++;
					star = maxstar[rank] - 1;
				} else star = 0;
			}
		}
	}
	if (rank == 0) cout << "Legend\n";
	else cout << rank <<'\n';
	return 0;
}
