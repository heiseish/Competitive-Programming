/** 
Those who cannot acknowledge themselves will eventually fail.        
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
#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1

const int maxn = 5003;
int vis[maxn];
int dfs_num[maxn];

unordered_map<int, vi> g;
void dfs1(int index) {
	for (auto &v : g[index]) {
		if (!vis[v]++) dfs1(v);
	}
}
vi topoSort;             // global vector to store the toposort in reverse order

void dfs2(int u) {    // change function name to differentiate with original dfs
  dfs_num[u] = DFS_BLACK;
  for (auto &v : g[u])
    if (dfs_num[v] == DFS_WHITE)
      dfs2(v);
  topoSort.push_back(u); }                   // that is, this is the only change

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	memset(vis, 0, sizeof vis);
	int n,m,s;
	cin>>n>>m>>s;
	forn(i, 1, m) {
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
	}
	memset(dfs_num, -1, sizeof dfs_num);
	for (int i = 1; i <= n; i++)            // this part is the same as finding CCs
		if (dfs_num[i] == DFS_WHITE)
		dfs2(i);
	reverse(topoSort.begin(), topoSort.end());                 // reverse topoSort
	vis[s]++;
	dfs1(s);
	int ans = 0;
	for (auto &i : topoSort) {
		if (!vis[i]++) {
			ans++;
			dfs1(i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
