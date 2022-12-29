/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
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
const int maxn = 500 + 3;
int n, m, s, t;
unordered_map<int, vector<int> > g;
int res[maxn][maxn] = {{ 0 }}, f, mf;
vi level;
int augment(int v, int minEdge) {
	if (!minEdge) return minEdge;
	if (v == t) 
		return minEdge;
	for (auto &next : g[v]) {
		if (level[next] == level[v] + 1 && res[v][next] > 0) {
			int ans = augment(next, min(minEdge, res[v][next]));
			if (!ans) continue;
			res[v][next] -= ans;
			res[next][v] += ans;
			return ans;
		}
	}
	return 0;
}


int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d %d %d", &n, &m, &s, &t);
	forn(i, 0, m - 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		res[u][v] = w;
		g[u].pb(v);
		g[v].pb(u);
	}
	mf = 0;
	while(1) {
		f = 0;
		bitset<maxn> vis; vis[s] = true;
		queue<int> q; q.push(s); 
		level.assign(maxn, -1);
		level[s] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &v : g[u]) 
				if (res[u][v] > 0 && !vis[v]) 
					vis[v] = true, q.push(v), level[v] = level[u] + 1;
		}
		while(f = augment(s, inf)) {
			mf += f;
		}
		if (level[t] == -1) break;
	}
	vector<int> ans;
	bitset<maxn> vis; vis[s] = true;
	queue<int> q; q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ans.pb(u);
		for (auto &v : g[u]) 
				if (res[u][v] > 0 && !vis[v]) 
					vis[v] = true, q.push(v);
	}
	printf("%ld\n", ans.size());
	for (auto &v : ans) printf("%d\n", v);
	return 0;
}
