/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
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
unordered_map<int, vi> g, gscc;
vi SCCno;
#define DFS_WHITE -1 
int n, m;
vi vis;
vi topoSort;             // global vector to store the toposort in reverse order
int ans;
int root;
void dfs(int index) {
	vis[index]=true;
	bool can = true;
	for(auto &v : gscc[index]) {
		if (!vis[v]) {
			can=false;dfs(v);}
	}
	if(can && index != root) {
		ans++;
		gscc[index].pb(root);
	}
}
void dfs2(int u) {    // change function name to differentiate with original dfs
  vis[u] = true;
  for (auto &v : gscc[u])
    if (!vis[v])
      dfs2(v);
  topoSort.push_back(u); }                   // that is, this is the only change


vi dfs_low,dfs_num;
int dfsNumberCounter;
vi S;
int numSCC;
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  vis[u] = true;
  for (auto &v : g[u]) {
    if (dfs_num[v] == DFS_WHITE)
      tarjanSCC(v);
    if (vis[v])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
              // this part is done after recursion
    while (1) {
      int v = S.back(); S.pop_back(); vis[v] = false;
	  SCCno[v]=numSCC;
      if (u == v) break;
    }
	 numSCC++; 
} }

void tarjanSCC2(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  vis[u] = true;
  for (auto &v : gscc[u]) {
    if (dfs_num[v] == DFS_WHITE)
      tarjanSCC2(v);
    if (vis[v])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
     numSCC++; 
    while (1) {
      int v = S.back(); S.pop_back(); vis[v] = false;
	 
      if (u == v) break;
    }
	
} }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		cin>>n>>m;
		g.clear();
		gscc.clear();
		topoSort.clear();
		SCCno.assign(n+1, -1);
		forn(i, 1, m) {
			int a, b;
			cin>>a>>b;
			g[a].pb(b);
		}

		dfs_num.assign(n+1, DFS_WHITE); dfs_low.assign(n+1, 0); 
		vis.assign(n+1, false);
  		dfsNumberCounter = numSCC = 0;
		for (int i = 1; i <=n; i++)
			if (dfs_num[i] == DFS_WHITE)
			tarjanSCC(i);
		if (numSCC==1) {
			cout << "0\n";
			continue;
		}

		/**
		Lemma: After converting SCC to vertices (DAG), the number of edges required to make the 
		DAG strongly connected is the max of (number of vertices with in-degree ==0,  number of vertices with out-degree==0)
		*/
		vi in(numSCC), out(numSCC);
		forn(i, 1, n) {
			for (auto &v : g[i]) {
				if (SCCno[v] != SCCno[i]) {
					gscc[SCCno[i]].pb(SCCno[v]);
					out[SCCno[i]]++;
					in[SCCno[v]]++;
				}
			}
		}
		int inH=0, outH=0;
		forn(i, 0, numSCC-1)  {
			if (in[i]==0) inH++;
			if (out[i]==0) outH++;
		}
		cout << max(inH, outH) <<'\n';
		
	}
	return 0;
}
