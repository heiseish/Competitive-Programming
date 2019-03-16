
/** 
Those who cannot acknowledge themselves will eventually fail.        
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
int n, m;
unordered_map<int, vi> g;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		g.clear();
		int ct = 0;
		unordered_map<string, int> sti;
		cin >> n >>m;
		vector<vi> s(m);
		string tt; cin.ignore();
		string ttt;
		forn(i,0,m-1) {
			getline(cin, tt);
			stringstream ss(tt);
			while(ss >> ttt) {
				bool flag=false;
				if (ttt.front() == '~') {
					ttt = ttt.substr(1);
					flag = true;
				}
				if (!sti.count(ttt)) sti[ttt] = ct++;
				int val = flag ? sti[ttt] + 20 : sti[ttt];
				s[i].pb(val);
				ss>>ttt;
			}
		}
		bool solved=false;
		forn(i, 0, (1 << n) - 1) {
			bool can = true;
			for (auto &v : s) {
				bool right = false;
				for (auto &nxt : v) {
					if (nxt < 20) right |= (i & (1 << nxt));
					else right |= !(i & (1 << (nxt - 20)));
				}
				if (!right) {
					can = false;
					break;
				}
			}
			if (can) {
				cout << "satisfiable\n";
				solved=true;
				break;
			}
		}
		if (!solved) cout << "unsatisfiable\n";
	}
	return 0;
}
