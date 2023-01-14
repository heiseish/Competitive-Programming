/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.
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
const int maxn = 2e3 + 5;
int n, m;
unordered_map<int, vi> g;
int res[maxn][maxn], mf, f, s, t;
vi level;

int augment(int v, int minEdge) {
	if (minEdge == 0) return 0;
	if (v == t) return minEdge;
	for (auto &next : g[v]) {
		if (level[next] == level[v] + 1 && res[v][next] > 0) {
			int ans = augment(next, min(minEdge, res[v][next]));
			if (ans == 0) continue;
			res[v][next] -= ans;
			res[next][v] += ans;
			return ans;
		}
	}
	return 0;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &m, &n);
	int sum = 0;
	s = 0;
	t = m + n + 1;
	forn(i, 1, m) {
		int a;
		scanf("%d", &a);
		sum+=a;
		res[0][i] = a;
		g[0].pb(i);
		g[i].pb(0);
	}
	forn(i, 1, m) 
		forn(j, m + 1, m + n) {
			res[i][j] = 1;
			g[i].pb(j);
			g[j].pb(i);
		}
	forn(i, m + 1, m + n) {
		int a;
		scanf("%d", &a);
		res[i][m + n + 1] = a;
		g[i].pb(m + n + 1);
		g[m + n + 1].pb(i);
	}
	mf = 0;
	while(1) {
		f = 0;
		queue<int> q; q.push(s); 
		level.assign(maxn, -1);
		level[s] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			// if (u == t) break;
			for (auto &v : g[u]) 
				if (res[u][v] > 0 && level[v] == -1) 
					q.push(v), level[v] = level[u] + 1;
		}
		if (level[t] == -1) break;
		while(f = augment(s, inf)) {
			mf += f;
		}
		
	}
	if (mf == sum) printf("yes\n");
	else printf("no\n");

	return 0;
}
