/** 
Wherever someone is still thinking of you, that place is your home.
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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 1e5 + 7;
int n, m;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter;
vi scc;
vector<bool> sccchecked;
unordered_map<int, vi> g, gp;
int numScc;
void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.pb(u);
	visited[u] = 1;
	for (auto& v : g[u]) {
		if (dfs_num[v] == -1)
			tarjan(v);
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
			
	}
	if (dfs_low[u] == dfs_num[u]) {
		numScc++;
		while(1) {
			int v = S.back(); 
			S.pop_back(); 
			visited[v] = 0;
			scc[v] = u;
			if (u == v) break;
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		g.clear();
		gp.clear();
		sccchecked.assign(n + 1, false);
		scc.assign(n + 1, -1);
		dfs_num.assign(n + 1, -1);
		dfs_low.assign(n + 1, 0);
		visited.assign(n + 1, 0);
		dfsNumberCounter = numScc = 0;
		forn(i, 1, m) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].pb(b);
			gp[b].pb(a);
		}
		forn(i, 1, n)
			if (dfs_num[i] == -1)
				tarjan(i);
		int ct = numScc;
		forn(i, 1, n)
			if (sccchecked[scc[i]])
				continue;
			else if (gp[i].size() == 0)
				continue;
			else {
				for (auto v : gp[i]) {
					if (scc[v] !=scc[i]) {
						ct--;
						sccchecked[scc[i]] = true;
						break;
					}
				}
				
			}
		printf("%d\n", ct);
	}
	return 0;
}
