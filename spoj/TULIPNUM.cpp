/** 
Those who do not understand true pain can never understand true peace.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

const int INF = 1 << 30;
/**
Start coding from here
*/

#define LSOne(S) ((S) & -(S))

typedef vector<int> vi;

class FenwickTree {                    // remember that index 0 is not used
private: vi ft; int n;        // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int _n) : n(_n) { ft.assign(n+1, 0); }    // n+1 zeroes
  FenwickTree(const vi& f) : n(f.size()-1) { ft.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {                                  // O(n)
      ft[i] += f[i];                                      // add this value
      if (i+LSOne(i) <= n)    // if index i has parent in the updating tree
        ft[i+LSOne(i)] += ft[i]; } }       // add this value to that parent
  int rsq(int j) {                                     // returns RSQ(1, j)
    int sum = 0; for (; j; j -= LSOne(j)) sum += ft[j];
    return sum; }
  int rsq(int i, int j) { return rsq(j) - rsq(i-1); }  // returns RSQ(i, j)
  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, int v) {
    for (; i <= n; i += LSOne(i)) ft[i] += v; }    // note: n = ft.size()-1
  int select(int k) { // O(log^2 n)
    int lo = 1, hi = n;
    for (int i = 0; i < 30; i++) { // 2^30 > 10^9 > usual Fenwick Tree size
      int mid = (lo+hi) / 2;                    // Binary Search the Answer
      (rsq(1, mid) < k) ? lo = mid : hi = mid; }
    return hi; }
};
struct Q {
	int l,r,idx;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	int cas=1;
	while(tc--) {
		cout<<"Case " << cas++ << ":\n";
		int n, q;
		cin>>n>>q;
		vi a(n+1);
		forn(i,1,n)cin>>a[i];
		FenwickTree ft(n);
		unordered_map<int, int> par;
		vector<Q> qu(q);
		forn(i,0,q-1) {
			cin>>qu[i].l>>qu[i].r;
			qu[i].idx=i;
		}
		sort(all(qu), [](const Q& lhs, const Q& rhs) {
			return lhs.r<rhs.r;
		});
		vi ans(q);
		int cur=0;
		forn(i,1,n) {
			if (par[a[i]]) ft.update(par[a[i]], -1);
			par[a[i]]=i;
			ft.update(i, 1);
			while(cur<q && qu[cur].r==i) {
				ans[qu[cur].idx]=ft.rsq(qu[cur].l, qu[cur].r);
				cur++;
			}
		}
		forn(i, 0, q-1) cout << ans[i]<<'\n';

	}
	return 0;
}
