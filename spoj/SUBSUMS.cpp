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
const ll maxn = (1 << 18);
ll n, a, b, nd, ng;
ll ans = 0LL;
ll d[20], g[20];
ll e[maxn], f[maxn];

ll cal(ll *a, ll id) {
	ll res = 0;
	for(int i = 0; id != 0; i++, id>>=1) {
		if (id & 1) res += a[i];
	}
	return res;
}
void solve() {
	ll ld = 1 << nd, lg = 1 << ng;
	forn(i, 0, ld - 1) e[i] = cal(d, i);
	sort(e, e + ld);
	forn(i, 0, lg - 1) {
		f[i] = cal(g, i);
		ll lowb = lower_bound(e, e + ld, a - f[i]) - e;
		ll uppb = upper_bound(e, e + ld, b - f[i]) - e;
		ans += (ll) uppb - lowb;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>a>>b;
	nd = n/2;
	ng = n - nd;
	forn(i, 0, nd - 1) cin>>d[i];
	forn(i, 0, ng - 1) cin>>g[i];
	solve();
	cout << ans<<'\n';
	return 0;
}
