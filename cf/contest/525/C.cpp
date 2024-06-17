/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.
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
	int n;
	scanf("%d", &n);
	vi a(n + 1, 0);
	forn(i, 1, n) scanf("%d", &a[i]);
	vector<pair<int, pi> > ans;
	long add = 0;
	for (int i = n; i >= 1; i--) {
		int need = i - 1;
		int res = (a[i] + add) % n;
		if (res < need) {
			add += (need - res);
			ans.pb({1, { i, need - res}});
		} else if (res > need) {
			add += (need + n - res);
			ans.pb({1, { i, need + n - res}});
		}
	}
	printf("%ld\n", ans.size() + 1);
	for (auto &v : ans) 
		printf("%d %d %d\n", v.st, v.nd.st, v.nd.nd);
	printf("2 %d %d\n", n, n);
	
	
	return 0;
}
