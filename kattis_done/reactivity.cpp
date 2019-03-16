/** 
Hard work is worthless for those that don’t believe in themselves.        
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
const int maxn = 1003;
vi g[maxn];
int adjmat[maxn][maxn];
int n, m;

vi topoSort, vis;         

void dfs2(int u) {    // change function name to differentiate with original dfs
  vis[u] = 1;
  for (auto &v : g[u])
    if (vis[v] == 0)
      dfs2(v);
  topoSort.push_back(u); }                   // that is, this is the only change


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>m;
	forn(i,1,m) {
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		adjmat[a][b] = 1;
	}

	 topoSort.clear();
	vis.assign(n, 0);
	for (int i = 0; i < n; i++)            // this part is the same as finding CCs
		if (vis[i] == 0)
		dfs2(i);
	// reverse(all(topoSort));                 // reverse topoSort
	bool can = true;
	for(int i = n-1; i >= 1; i--) if (!adjmat[topoSort[i]][topoSort[i-1]]) can = false;
	if (!can) cout << "back to the lab";
	else for(int i = n-1; i >= 0; i--) cout << topoSort[i] << ' ';
	cout <<'\n';

	return 0;
}
