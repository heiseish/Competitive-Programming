/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	cin>>n>>m;
	unordered_map<int, pll> g;
	forn(i, 1, n) {
		ll a;
		cin>>a;
		g[i].st=a;
	}
	vpll c(n);
	forn(i, 0, n-1) {
		cin>>c[i].st;
		g[i+1].nd = c[i].st;
		c[i].nd=i+1;
	}
	sort(all(c), [](const pi& lhs, const pi& rhs) {
		return lhs.st > rhs.st || (lhs.st == rhs.st && lhs.nd > rhs.nd);
	});
	forn(i, 1, m) {
		ll t, d;
		cin>>t>>d;
		ll ans = 0LL;
		ll temp = min(g[t].st, d);
		ans += temp * g[t].nd;
		d-=temp;
		g[t].st-=temp;
		while(d!=0) {
			if (c.empty()) break;
			pll f = c.back();
			ll tmp = min(g[f.nd].st, d);
			ans+= tmp * f.st;
			d-=tmp;
			g[f.nd].st-=tmp;
			if (g[f.nd].st==0) c.pop_back();
		}
		if (d != 0) cout << "0\n";
		else cout<< ans<<'\n';

	}
	return 0;
}
