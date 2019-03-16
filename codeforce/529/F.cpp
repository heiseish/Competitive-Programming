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

const int maxn = 2e5 + 3;
int d[maxn];
vector<pair<ll, pi> > g;
int find(int index) {
	if (d[index] == -1) return index;
	return d[index] = find(d[index]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	d[a] = b;
}

bool isSameSet(int a, int b) {
	return find(a) == find(b);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(d, -1, sizeof d);
	int n, m;
	cin >> n >> m;
	vector<pair<ll, int> > a(n);
	forn(i, 0, n - 1) {
		cin >> a[i].st;
		a[i].nd = i + 1;
	}
	sort(all(a));
	forn(i, 1, n - 1) {
		g.pb({ a[i].st + a[0].st, { a[i].nd, a[0].nd}});
	}
	forn(i, 0, m - 1) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		g.pb({w, {a, b}});
	}
	sort(all(g));
	ll ans = 0L;
	for (auto &e : g) {
		if (!isSameSet(e.nd.st, e.nd.nd)) {
			ans += e.st;
			join(e.nd.st, e.nd.nd);
		}
	}
	cout << ans << '\n';
	return 0;
}
