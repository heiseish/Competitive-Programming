/** 
Wherever someone is still thinking of you, that place is your home.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
int n, m, k;
const int maxn = 1e5 + 5;
int d[maxn], visited[maxn], dist[maxn];
unordered_map<int, vpi> g;
int find(int index) {
	if (d[index] == -1) return index;
	return d[index] = find(d[index]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a==b) return;
	d[a] = b;
}

void dfs(int index, int d) {
	visited[index] = 1;
	dist[index] = d;
	for (auto &v : g[index]) {
		if (visited[v.nd] == -1) {
			dfs(v.nd, d + v.st);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	rsa(d, -1);
	rsa(visited, -1);
	cin >> n >> m >> k;
	vector<int> sp(k);
	forn(i, 0, k - 1) cin >> sp[i];
	vector<pair<int, pi> > el;
	forn(i, 0, m - 1) {
		int a, b, w;
		cin >> a >> b >> w;
		el.pb({ w, pi(a, b) });
	}
	sort(all(el), greater<pair<int, pi> > ());
	for(auto &v : el) {
		if (find(v.nd.st) != find(v.nd.nd)) {
			join(v.nd.st, v.nd.nd);
			g[v.nd.st].pb(pi(v.st, v.nd.nd));
			g[v.nd.nd].pb(pi(v.st, v.nd.st));
		}
	}
	dfs(sp[0], 0);
	int maxdist = -1;
	forn(i, 1, k - 1) maxdist = max(maxdist, dist[sp[i]]);
	forn(i, 0, k - 1) cout << maxdist << ' ';
	return 0;
}
