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

int getIdx(int x) { return 2 * x - 1; };
int getOff(int x) { return 2 * x; };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vi a(2*n + 1);
	forn(i, 1, n) {
		a[getIdx(i)]=s[i-1]=='1'?1:0;
	}
	vi off(2*n + 1);
	forn(i, 1, n-1) {
		if (a[getIdx(i)] && a[getIdx(i+1)]) off[getOff(i)]=1;
	}
	FenwickTree main(a), os(off);
	while(m--) {
		int t;
		cin>>t;
		if(t==1) {
			int x;
			cin>>x;
			if (a[getIdx(x)]==0) {
				if (a[getIdx(x-1)]) {
					os.update(getOff(x-1), 1);
					off[getOff(x-1)]=1;
				}
				if (a[getIdx(x+1)]) {
					os.update(getOff(x), 1);
					off[getOff(x)]=1;
				}
				main.update(getIdx(x), 1);
				a[getIdx(x)] =1;
			} else {
				if (a[getIdx(x-1)]) {
					os.update(getOff(x-1), -1);
					off[getOff(x-1)]=0;
				}
				if (a[getIdx(x+1)]) {
					os.update(getOff(x), -1);
					off[getOff(x)]=0;
				}
				main.update(getIdx(x), -1);
				a[getIdx(x)]=0;
			}

		} else {
			int l, r;
			cin>>l>>r;
			// debug(main.rsq(getIdx(l), getIdx(r)));
			// debug(os.rsq(getOff(l), getOff(r-1)));
			cout<<main.rsq(getIdx(l), getIdx(r)) - os.rsq(getOff(l), getOff(r-1))<<'\n';
		}
	}
	return 0;
}
