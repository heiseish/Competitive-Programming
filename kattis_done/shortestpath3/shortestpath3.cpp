/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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

const ll inf = 2000000007;
/**
Start coding from here
*/
const int maxn = 1e3 + 3;
int seen[maxn], ne[maxn];
bool reach[maxn];
int n, m, q, s;
int dest;
unordered_map<int, vector<pair<ll, int> > > g;

bool dfs(int index) {
	if (seen[index]++) return false;
	if (index == dest) return true;
	for (auto &v : g[index])
		if (dfs(v.nd))
			return true;
	return false;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d %d %d %d", &n, &m, &q, &s) && (n || m || q || s)) {
		memset(reach, false, sizeof reach);
		memset(ne, 0, sizeof ne);
		g.clear();
		forn(i, 0, m - 1) {
			int a, b;
			ll w;
			scanf("%d %d %lld", &a, &b, &w);
			g[a].pb({ w, b});
		}
		vll dist(n, inf); dist[s] = 0L;
		forn(i, 0, n - 2) 
			forn(u, 0, n - 1)
				if (dist[u] != inf) for(auto &v : g[u])
					dist[v.nd] = min<ll>(dist[v.nd], dist[u] + v.st);
		vi nc;
		forn(u, 0, n - 1)
			if (dist[u] != inf) for (auto &v : g[u]) 
				if (dist[v.nd] > dist[u] + v.st) {
					ne[u] = 1;
				}
					
		forn(u, 0, n - 1)
			if (ne[u]) nc.pb(u);

		forn(i, 1, q) {
			scanf("%d", &dest);
			if (dist[dest] == inf) {
				printf("Impossible\n");
				continue;
			}
			for (auto i : nc) {
				if (reach[dest]) break;
				memset(seen, 0, sizeof seen);
				reach[dest] = dfs(i);
			}
			if (reach[dest]) printf("-Infinity\n");
			else printf("%lld\n", dist[dest]); 
		}
		
	}
	return 0;
}
