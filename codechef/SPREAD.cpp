/** 
When a man learns to love, he must bear the risk of hatred.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (ll)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

using namespace std;
typedef long long ll;
typedef vector<long long> vll;

const ll INF = 1 << 30;
/**
Start coding from here
*/

#define LSOne(S) ((S) & -(S))


class FenwickTree {                    // remember that index 0 is not used
private: vll ft; ll n;        // recall that vi is: typedef vector<ll> vi;
public: FenwickTree(ll _n) : n(_n) { ft.assign(n+1, 0); }    // n+1 zeroes
  FenwickTree(const vll& f) : n(f.size()-1) { ft.assign(n+1, 0);
    for (ll i = 1; i <= n; i++) {                                  // O(n)
      ft[i] += f[i];                                      // add this value
      if (i+LSOne(i) <= n)    // if index i has parent in the updating tree
        ft[i+LSOne(i)] += ft[i]; } }       // add this value to that parent
  ll rsq(ll j) {                                     // returns RSQ(1, j)
    ll sum = 0; for (; j; j -= LSOne(j)) sum += ft[j];
    return sum; }
  ll rsq(ll i, ll j) { return rsq(j) - rsq(i-1); }  // returns RSQ(i, j)
  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(ll i, ll v) {
    for (; i <= n; i += LSOne(i)) ft[i] += v; }    // note: n = ft.size()-1
  ll select(ll k) { // O(log^2 n)
    ll lo = 1, hi = n;
    for (ll i = 0; i < 30; i++) { // 2^30 > 10^9 > usual Fenwick Tree size
      ll mid = (lo+hi) / 2;                    // Binary Search the Answer
      (rsq(1, mid) < k) ? lo = mid : hi = mid; }
    return hi; }
};

class RUPQ : FenwickTree {    // RUPQ variant is a simple extension of PURQ
public:
  RUPQ(int n) : FenwickTree(n) {}
  ll point_query(int i) { return rsq(i); }
  void range_update(int i, int j, ll v) { update(i, v), update(j+1, -v); }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll n, m, c;
	cin>>n>>m>>c;
	RUPQ ft(n);
	forn(i, 1, n) ft.range_update(i, i, c);
	while(m--) {
		char c;
		cin>>c;
		if (c=='S') {
			ll u, v, k;
			cin>>u>>v>>k;
			ft.range_update(u, v, k);
		} else {
			int p;
			cin>>p;
			cout << ft.point_query(p) <<'\n';
		}
	}
	return 0;
}
