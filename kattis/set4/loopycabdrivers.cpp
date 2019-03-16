/** 
Hard work is worthless for those that don’t believe in themselves.        
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
unordered_map<string, int> sti;
unordered_map<int, string> its;
vi g[20007];
int ct= 0, n;
vi S, visited;                                    // additional global variables
int numSCC;
vi dfs_low, dfs_num;
int dfsNumberCounter = 0;
vector<string> avoid;
vector<vector<string> > okay;
void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.push_back(u);           // stores u in a vector based on order of visitation
  visited[u] = 1;
  for (auto &v : g[u]) {
    if (dfs_num[v] == -1)
      tarjanSCC(v);
    if (visited[v])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
	int cur = numSCC++;           // this part is done after recursion
	vector<string> ans;
    while (1) {
      int v = S.back(); S.pop_back(); visited[v] = 0;
	  ans.pb(its[v]);
      if (u == v) break;
    }
	if (sz(ans) == 1) avoid.push_back(ans.back());
	else {
		sort(all(ans));
		okay.pb(ans);
	}
} }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	sti.reserve(10000);
	its.reserve(10000);
	forn(i, 1, n) {
		string a, b;
		cin>>a>>b;
		int aidx, bidx;
		if (!sti.count(a)) {
			sti[a] = ct;
			its[ct] = a;
			ct++;
		}
		if (!sti.count(b)) {
			sti[b] = ct;
			its[ct] = b;
			ct++;
		}
		aidx = sti[a];
		bidx = sti[b];
		g[aidx].pb(bidx);
	}
	dfs_num.assign(ct, -1); dfs_low.assign(ct, 0); visited.assign(ct, 0);
	dfsNumberCounter = numSCC = 0;
	for (int i = 0; i < ct; i++)
		if (dfs_num[i] == -1)
			tarjanSCC(i);
	sort(all(avoid));
	sort(all(okay));
	for (auto &v : okay) {
		cout << "okay ";
		for (auto &k : v) {
			cout << k << ' ';
		}
		cout <<"\n";
	}
	if (!avoid.empty()) {
		cout << "avoid ";
		for (auto &v : avoid) cout << v << ' ';
		cout <<'\n';
	}
	
	return 0;
}
