/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
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


#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  int rsq(int b) {                                     // returns RSQ(1, b)
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {                              // returns RSQ(a, b)
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

struct Node {
	int i, j, k, type, id;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, q;
	cin>>n;
	vector<Node> a(n + 1);
	FenwickTree tree(n);
	forn(i, 1, n) {
		cin>>a[i].k;
		a[i].i = a[i].j = i;
		a[i].type=-1;
	}
	cin>>q;
	a.resize(n + q + 1);
	forn(i, 1, q) {
		cin>>a[i+n].i>>a[i+n].j>>a[i+n].k;
		a[i+n].type=0;
		a[i+n].id=i;
	}
	sort(all(a), [](Node &lhs, Node &rhs) {
		return lhs.k > rhs.k || (lhs.k == rhs.k && lhs.type > rhs.type);
	});
	vi ans(q+1);
	forn(i, 0, n + q - 1) {
		// cout << a[i].i << ' ' << a[i].j <<' ' <<  a[i].k << '\n';
		if (a[i].type==-1) tree.adjust(a[i].i, 1);
		else ans[a[i].id] = tree.rsq(a[i].i, a[i].j);
	}
	forn(i, 1, q) cout << ans[i]<<'\n';
	return 0;
}
