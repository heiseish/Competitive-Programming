/** 
Those who cannot acknowledge themselves will eventually fail.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

ll extendedEuclid(ll a, ll b, ll &x, ll& y) {
	ll xx = y=  0;
	ll yy = x = 1;
	while(b) {
		ll q = a/b;
		ll t = b; b = a % b; a = t;
		t =xx; xx = x-q*xx;x=t;
		t = yy; yy= y-q * yy;y=t;
	}
	return a;
}
const int maxc = 1e9;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		ll k, c;
		cin>>k>>c;
		// if (k == c && c == 1) {
		// 	cout << "2\n";
		// 	continue;
		// }
		ll x, y;
		ll d = extendedEuclid(c, k, x, y);
		if (x%d!=0 || y%d!=0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		ll ans = x/d;
		ll candies = -y/d;
		
		if (ans < 0) {
			ll n = -ans/(k/d) + 1;
			ans += (k/d) * n;
			candies += (c/d) * n;
		}
		while (candies <= 0) {
			ans += k/d;
			candies += c/d;
		}
		cout << ans <<'\n';
	}
	return 0;
}
