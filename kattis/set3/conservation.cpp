/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
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
int n, m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		cin>>n>>m;
		vector<unordered_set<int> > g(n+1), d(n+1);
		vi a(n+1);
		forn(i,1,n) cin>>a[i];
		forn(i,1,m) {
			int c, b;
			cin>>c>>b;
			g[c].insert(b);
			d[b].insert(c);
		}
		
		int fin = INF;
		forn(i, 1, 2) {
			vi vis(n+1, 0);
			deque<int> q;
			vector<unordered_set<int> > g1(g), d1(d);
			forn(i, 1, n) {
				if(d1[i].empty()) {
					if (a[i] == 1) q.push_front(i);
					else q.push_back(i);
				}
			}
			int ans = 0;
			int cur = i;
			
			while(!q.empty()) {
				int t;
				if (cur == 1) {
					t = q.front();
					q.pop_front();
				} else {
					t = q.back();
					q.pop_back();
				}
				vis[t]++;
				if (cur != a[t]) {
					cur = a[t];
					ans++;
				}
				for (auto &dep : g1[t]) {
					if (vis[dep]) continue;
					d1[dep].erase(t);
					if (d1[dep].empty()) {
						if (a[dep] == 1) q.push_front(dep);
						else q.push_back(dep);
					}
				}
			}
			fin=min(fin, ans);
		
		}
		cout<<fin<<'\n';
	}
	return 0;
}
