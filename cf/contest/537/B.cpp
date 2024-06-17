/** 
Hard work is worthless for those that don’t believe in themselves.        
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
	ll n, k, m;
	cin>>n>>k>>m;
	vi a(n);
	ll tot = 0LL;
	forn(i, 0, n-1) {
		cin>>a[i];
		tot+=a[i];
	}
	sort(all(a));
	ld best = 1.0 * (tot + min(k * n, m)) / n;
	forn(i, 0, n-2) {
		if (m >= i + 1) tot-=a[i];
		else break;
		ld ans = 1.0 * (tot + min(k * (n - i - 1), m - 1 - i)) / (n - i - 1);
		best = max(best, ans);
	}
	cout<<setprecision(15) << best <<'\n';
	return 0;
}
