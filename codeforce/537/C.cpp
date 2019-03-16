/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
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
ll n, k, A, B;
vi a;
unordered_map<int, int> g;

ll solve(ll l, ll r) {
	if (l == r) return g.count(l) ? g[l] * B : A;
	int lowb = lower_bound(all(a), l) - a.begin();
	int uppb = upper_bound(all(a), r) - a.begin();
	int numAve = uppb - lowb;
	// debug(l);
	// debug(r);
	// debug(numAve);
	if (numAve == 0) return A;
	else {
		ll ans = B * (r - l + 1) * numAve;
		// debug(ans);
		ll mid = (l + r)>>1;
		return min(ans, solve(l, mid) + solve(mid+1, r));
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>k>>A>>B;
	a.assign(k, 0);
	forn(i, 0, k-1) {
		cin>>a[i];
		g[a[i]]++;
	}
	sort(all(a));
	cout << solve(1, 1<<n) <<'\n';
	return 0;
}
