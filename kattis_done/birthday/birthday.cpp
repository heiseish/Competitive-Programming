/** 
When a man learns to love, he must bear the risk of hatred.
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
const int maxn = 1e2 + 3;
int p, c;
unordered_map<int, vi> g;
int dfsNC;
int dfs_low[maxn], dfs_num[maxn], par[maxn];
int ct, rc;
bool bridge = false;
void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = dfsNC++;
	ct++;
	for (auto& v : g[u]) {
		if (dfs_num[v] == -1) {
			par[v] = u;
			if (u == 0) rc++;
			tarjan(v);
			if (dfs_low[v] > dfs_num[u]){
				bridge = true;
				return;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != par[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d %d", &p, &c) && (p || c)) {
		memset(dfs_num, -1, sizeof dfs_num);
		g.clear();
		forn(i, 1, c) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		dfsNC = ct = rc = 0;
		bridge = false;
		tarjan(0);
		if (bridge || ct != p)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
