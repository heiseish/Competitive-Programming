/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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
const int maxn = 1e5 +3;
vpi el;
int v[maxn], l[maxn];
unordered_map<int , vi> g;
int f = -1, bf = -1;
void dfs(int index, int Time) {
	v[index]++;
	if (Time > bf) {
		f = index;
		bf = Time;
	}
	for (auto &u : g[index]) {
		if (!v[u])
			dfs(u, Time + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, s;
	cin >> n >> s;
	forn(i, 0, n - 2) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		el.pb({a, b});
	}
	rsa(l, 0);
	dfs(1, 0);
	int ct = 0;
	for (auto &v : g) {
		if (v.nd.size() == 1) l[v.st]++;
	}
	for (auto &e : el) {
		if (l[e.st] || l[e.nd]) ct++;
	}
	int md = n > 2 ? 2 : 1;
	cout << fixed << setprecision(10) << 1.0 * s * md / ct  << '\n';
	return 0;
}
