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

const int inf = 1 << 30;
/**
Start coding from here
*/

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n, x, y, d;
		scanf("%lld %lld %lld %lld", &n,&x, &y, &d);
		if (abs(y - x)%d == 0) printf("%lld\n", abs(y - x) / d);
		else if ((y - 1)%d != 0 && (n - y)%d != 0) puts("-1");
		else if ((y - 1)%d != 0 && (n - y)%d == 0) printf("%lld\n", (long long) ceil(1.0 * (n - x) / d) + (n - y)/d);
		else if ((y - 1)%d == 0 && (n - y)%d != 0) printf("%lld\n", (long long) ceil(1.0 * (x - 1) / d) + (y - 1)/d);
		else printf("%lld\n", min((long long) ceil(1.0 * (x - 1) / d) + (y - 1)/d, (long long) ceil(1.0 * (n - x) / d) + (n - y)/d));
	}
	return 0;
}
