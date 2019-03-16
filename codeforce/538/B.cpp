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
#define mp make_pair

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
ll n, m, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	
	cin>>n>>m>>k;
	vll a(n), b(n);
	forn(i, 0, n-1) {
		cin>>a[i];
		b[i] = a[i];
	}
	sort(all(b));
	ll lowb = b[n - m * k];
	cout << (ll) accumulate(b.end() - m * k, b.end(), 0LL) << '\n';
	unordered_map<int, int> g;
	forn(i, n-m*k, n-1) {
		g[b[i]]++;
	}
	int curk = 0, curnum=0;
	vi ans;
	for(int i = 0; i < n; ++i) {
		if (g[a[i]]) {
			curnum++;
			g[a[i]]--;
		}
		if (curnum >= m && curk < k) {
			curk++;
			curnum = 0;
			if (curk <= k - 1) ans.pb(i + 1);
		}
		
	}
	for (auto &v : ans) cout << v << ' ';
	cout << '\n';
	return 0;
}
