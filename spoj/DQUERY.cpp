/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
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
	int i, j, idx;
};
const int MAX_A = 1e6 + 3;
int par[MAX_A];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<int> a(n + 1);
	FenwickTree ft(n);
	memset(par, -1, sizeof par);
	forn(i, 1, n) cin>>a[i];
	int m;
	cin>>m;
	vector<Q> q(m);
	forn(i, 0, m-1) {
		cin>>q[i].i>>q[i].j;
		q[i].idx=i;
	}
	vi ans(m, 0);
	sort(all(q), [](const Q& lhs, const Q& rhs)  {
		return lhs.j<rhs.j;
	});
	int cur=0;
	forn(i, 1, n) {
		if (par[a[i]] != -1) 
			ft.update(par[a[i]], -1);
		par[a[i]]=i;
		ft.update(i, 1);
		while(cur<m && q[cur].j==i) {
			ans[q[cur].idx]=ft.rsq(q[cur].i, q[cur].j);
			cur++;
		}
	}
	forn(i, 0, m-1) cout<< ans[i]<<'\n';
	return 0;
}
