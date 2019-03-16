/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?
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
const int maxn = 1e2 + 7;
int en[maxn], s[maxn];
int n;
unordered_map<int, vi> g;

bool dfs(int index) {
	if (s[index]++) return false;
	if (index == n) return true;
	for (auto &v : g[index]) {
		if (dfs(v))
			return true;
	}
	return false;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d", &n) && n != -1) {
		g.clear();
		forn(i, 1, n) {
			scanf("%d", &en[i]);
			int m;
			scanf("%d", &m);
			forn(j, 1, m) {
				int a;
				scanf("%d", &a);
				g[i].pb(a);
			}
		}

		vi dist(n + 1, -inf); dist[1] = 100;
		// vi dist2(n + 1, -inf); dist2[1] = 0;
		forn(i, 1, n - 1)
			forn(u, 1, n) {
				if (dist[u] != -inf) for (auto &v : g[u]) {
					if (dist[u] + en[v] > 0 && dist[u] + en[v] > dist[v]) {
						dist[v] = dist[u] + en[v] ;
					}
				}
			}
	
		memset(s, 0, sizeof s);
		if (!dfs(1)) {
			printf("hopeless\n");
			continue;
		}
		bool hasPositiveCycle = false;
		forn(u, 1, n) {
			if (dist[u] != -inf) for (auto &v : g[u]) 
				if (dist[u] + en[v] > 0 && dist[u] + en[v] > dist[v]) {
					memset(s, 0, sizeof s);
					hasPositiveCycle |= dfs(u);
					if (hasPositiveCycle)
						break;
					
				}
		}
		if (hasPositiveCycle) {
			// debug("hi");
			printf("winnable\n");
			continue;
		}
		// forn(i, 1, n) debug(dist[i]);
		if (dist[n] <= 0) printf("hopeless\n");
		else printf("winnable\n");
	}
	return 0;
}
