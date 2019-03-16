/** 
"You think you're the only ones who matter. You think you can put off death. But that peace made you foolish and thoughtless. If you kill someone, someone else will kill you… this hatred binds us together."
"Those who do not understand true pain can never understand true peace."

I’m the only one who can bear the full brunt of your hate! It’s my job, no one else’s! I’ll bear the burden of your hatred… and we’ll die together!

When a man learns to love, he must bear the risk of hatred.

Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.

Hard work is worthless for those that don’t believe in themselves.

*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
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
	int n,m;
	while(scanf("%d %d", &n, &m) && n && m) {
		int a, b;
		double best = 1.0 * inf;
		forn(i, 0, n - 1) {
			int x, z;
			scanf("%d %d", &x, &z);
			if (x > m) continue;
			double net = 1.0 * z / x;
			if (net < best) {
				best = net;
				a = x;
				b = z;
			} else if (net == best && x > a) {
				a = x;
				b = z;
			}
		}
		if (best == 1.0 * inf) {
			printf("No suitable tickets offered\n");
		} else {
			printf("Buy %d tickets for $%d\n", a, b);
		}
	}
	return 0;
}
