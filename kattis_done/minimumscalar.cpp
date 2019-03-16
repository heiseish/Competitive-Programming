/** 
Those who cannot acknowledge themselves will eventually fail.
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
	forn(i, 1, t) {
		int n;
		scanf("%d", &n);
		vi a(n), b(n);
		forn(j, 0, n - 1) scanf("%d", &a[j]);
		forn(j, 0, n - 1) scanf("%d", &b[j]);
		sort(all(a));
		sort(all(b), greater<int>());
		ll sum = 0L;
		forn(j, 0, n - 1) sum += 1L * a[j] * b[j];
		printf("Case #%d: %lld\n", i, sum);
	}
	return 0;
}
