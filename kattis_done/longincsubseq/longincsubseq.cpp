/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.
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

const int maxn = 1e5 + 7;
int par[maxn];
int n;

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d", &n) != EOF) {
		vll a(n);
		vi temp;
		memset(par, -1, sizeof par);
		forn(i, 0, n-1) scanf("%lld", &a[i]);
		forn(i, 0, n-1) {
			if (temp.empty()) {
				temp.pb(i);
				continue;
			}
			if (a[i] > a[temp.back()]) {
				par[i] = temp.back();
				temp.pb(i);
				continue;
			}
			int j = lower_bound(all(temp), i, [&a] (const auto& lhs, const auto& rhs) {
				return a[lhs] < a[rhs];
			}) - temp.begin();
			temp[j] = i;
			if (j > 0) par[i] = temp[j - 1];
		}
		vi res;
		int cur = temp.back();
		while(cur != -1) {
			res.pb(cur);
			cur = par[cur];
		}
		printf("%ld\n", temp.size());
		for(int i = res.size() - 1; i >= 0;i--) printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}
