/** 
When a man learns to love, he must bear the risk of hatred.
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

// const int maxn = 1e9 + 7;
// const int n = 1e9;
// ll dp[maxn];

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// dp[0] = 0;
	// forn(i, 1, n) {
	// 	if (i%2!=0) dp[i] = dp[i-1] - i;
	// 	else dp[i] = dp[i-1] + i;
	// }
	ll q;
	scanf("%lld", &q);
	while(q--) {
		ll l, r;
		scanf("%lld %lld", &l, &r);
		l--;
		if (l%2 == 0) l/=2;
		else l=-(l+1)/2;
		if(r%2==0) r/=2;
		else r=-(r+1)/2;
		printf("%lld\n", r - l);
	}
	return 0;
}
