/** "You think you\'re the only ones who matter. You think you can put off death. But that peace made you foolish and thoughtless. If you kill someone, someone else will kill you… this hatred binds us together."
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
#define LSOne(S) (S & (-S))

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

class FenwickTree {
private:
  vll ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  ll rsq(int b) {                                     // returns RSQ(1, b)
    ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q;
	// cin >> n >> q;
	scanf("%d %d", &n, &q);
	FenwickTree ft(n);
	while(q--) {
		char op;
		// cin >> op;
		scanf(" %c", &op);
		if (op == '+') {
			ll k, v;
			// cin >> k >> v;
			scanf("%lld %lld", &k, &v);
			ft.adjust(k + 1, v);
		} else {
			int a;
			// cin >> a;
			scanf("%d", &a);
			if (a == 0) printf("0\n");
			else printf("%lld\n", ft.rsq(a));
		}
	}
	return 0;
}
