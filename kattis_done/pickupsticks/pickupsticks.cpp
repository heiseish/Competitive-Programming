/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone
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
const int maxn = 1e6 + 7;
bool e[maxn] = { false };
unordered_map<int, vi> g;
int n, m;
vi res;
bool can = true;
int dfsNumberCounter, numScc;

void dfs(int index) {
	e[index] = true;
	for (auto i : g[index]) {
		if (!can) return;
		if (!e[i]) {
			dfs(i);
			
		}
	}
	if (!can) return;
	res.pb(index);
}

vi dfs_num, dfs_low, S, t_visited;
void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.pb(u);
	t_visited[u] = 1;
	for (auto& v : g[u]) {
		if (dfs_num[v] == -1)
			tarjan(v);
		if (t_visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
			
	}
	if (dfs_low[u] == dfs_num[u]) {
		numScc++;
		while(1) {
			int v = S.back(); S.pop_back(); t_visited[v] = 0;
			if (u == v) break;
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &n, &m);
	dfs_num.assign(n + 1, -1);
	dfs_low.assign(n + 1, 0);
	t_visited.assign(n + 1, 0);
	dfsNumberCounter = numScc = 0;
	forn(i, 1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b);
	}
	forn(i, 1, n) {
		if (dfs_num[i] == -1)
			tarjan(i);
	}
	if (numScc != n) {
		printf("IMPOSSIBLE\n");
	}
	else {
		forn(i, 1, n)
			if (!e[i])
				dfs(i);
		for(int i = (int)res.size() - 1; i>=0;i--) 
			printf("%d\n", res[i]);
	}
		
	return 0;
}
