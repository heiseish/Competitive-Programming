#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back

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
const int maxn = 2e5 + 7;
ll a[maxn];
unordered_map<ll, ll> dp;
int main() {
	int n;
	scanf("%d", &n);
	ll s = 0;
	forn(i, 0, n-1) {
		scanf("%lld", &a[i]);
		s+=a[i];
		if (dp.find(a[i]) == dp.end()) dp[a[i]] = 1;
		else dp[a[i]]++;
	}
	vi res;
	forn(i,0,n-1) {
		if ((s - a[i])%2 != 0) continue;
		if (dp.find((s - a[i])/2) != dp.end()) {
			if (a[i] != (s - a[i])/2 || (a[i] == (s - a[i])/2 &&  dp[(s - a[i])/2] > 1)) 
				res.pb(i + 1);
		}
	}
	printf("%ld\n", res.size());
	for (auto i : res) printf("%d ", i);
	printf("\n");

	
	return 0;
}
