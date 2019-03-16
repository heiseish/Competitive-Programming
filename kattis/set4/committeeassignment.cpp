/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 16;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	while(cin>>n>>m && (n || m)) {
		int g[maxn];
		unordered_map<string, int> sti;
        int ct = 0;
        forn(i,1 , m) {
            string s, t;
            cin>>s>>t;
            int sidx, tidx;
            if(!sti.count(s)) {
                sti[s] = ct;
                sidx=ct++;
				g[sidx] = 1 << sidx;
            } else sidx = sti[s];

            if(!sti.count(t)) {
                sti[t] = ct;
                tidx=ct++;
				g[tidx] = 1 << tidx;
            } else tidx = sti[t];

            g[sidx] |= (1 << tidx);
            g[tidx] |= (1 << sidx);
        }
		int ans = 1;
		forn(i, 1, (1 << n) - 1) {
			int d = i;
			vi f;
			int idx = 0;
			while(d > 0) {
				if (d & 1) f.pb(idx);
				idx++;
				d>>=1;
			}
			bool can = true;
			for (auto &v : f) for (auto &c : f) {
					if (!(g[v] & (1 << c))) {
						can = false;
						break;
					}
			}
			if (can) ans = max(ans, sz(f));
		}
		cout << ans << '\n';
	}

	return 0;
}
