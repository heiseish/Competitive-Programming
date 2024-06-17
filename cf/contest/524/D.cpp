/** 
Those who do not understand true pain can never understand true peace.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first

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
		ll n, k;
		scanf("%lld %lld", &n, &k);
		if (k == 0) {
			printf("YES 0\n");
		}
		if (log(k * 3 + 1) / log(4) > 1.0 * n) printf("NO\n");
		else {
			if (log( k * 3 + 1) / log(4) < 1.0 * n - 1.0) printf("YES 1\n");
			else {
				ll expc = (ll)(log( k * 3 + 1) / log(4));
				ll s = 2 + pow(n, expc);
				ll cur = 2;
				ll exx = 1;
				bool can = true;
				while(s < k) {
					if (k <= s + cur) {
						can  = false;
						break;
					} else {
						s += (cur + 1) + (cur + 1)* 
					}
				}
			}
		}
	}
	return 0;
}
