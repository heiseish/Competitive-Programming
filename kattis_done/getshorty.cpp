/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.
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

const int inf = 1 << 20;
/**
Start coding from here
*/
const int maxn = 1e4 + 3;
double d[maxn];
int e[maxn][maxn];
int n, m;
unordered_map<int, vector<pair<double, int> > > g;
void djikstra (int index) {
	forn(i, 0, n - 1) d[i] = -1.0 * inf;
	// priority_queue<pair<double, int>, vector< pair<double, int> >,
	// 	greater<pair<double, int> > > pq;
	priority_queue<pair<double, int> > pq;
	d[index] = 0.0;
	pq.push({0.0, index});
	while(!pq.empty()) {
		pair<double, int> cur = pq.top(); pq.pop();
		auto [dist, u] = cur;
		if (dist < d[u]) continue;
		for (auto v :g[u]) {
			if (d[v.nd] < d[u] + v.st && !e[u][v.nd]){
				d[v.nd] = d[u] + v.st;
				pq.push({ d[v.nd], v.nd });
				e[u][v.nd] = 1;
			}
		}
		
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d %d", &n, &m) && (n || m)) {
			g.clear();
			memset(e, 0, sizeof e);
			forn(i, 0, m - 1) {
			int a, b;
			double w;
			scanf("%d %d %lf", &a, &b, &w);
			g[a].pb({ log(w), b });
			g[b].pb({ log(w), a });
		}
		djikstra(0);
		printf("%.4f\n", exp(d[n - 1]));
	}
	

	return 0;
}
