/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
class FenwickTree2D {                    // remember that index 0 is not used
private: vvll ft; int n, m;        // recall that vi is: typedef vector<int> vi;
public: FenwickTree2D(int _n, int _m) : n(_n), m(_m) { ft.assign(n+1, vll(m+1, 0LL)); }    // n+1 zeroes
void update(int i, int j, ll v) {
    for (int x=i; x <= n; x += LSOne(x)) for(int y=j;y<=m;y+=LSOne(y)) 
	ft[x][y] += v; }    // note: n = ft.size()-1

  FenwickTree2D(const vector<vi>& f) : n(f.size()-1), m(f[0].size() - 1) { 
	  ft.assign(n+1, vll(m+1, 0LL));
    for (int i = 1; i <= n; i++) {                                  // O(n)
		for(int j = 1;j<=m;j++) {
			update(i, j, f[i][j]);
		}
	} }       // add this value to that parent
  ll rsq(int i, int j) {                                     // returns RSQ(1, j)
    ll sum = 0LL; 
	for (int x=i; x; x -= LSOne(x)) for(int y=j;y;y-=LSOne(y))  
			sum += ft[x][y];
    return sum; }
  ll rsq(int i1, int j1, int i2, int j2) { 
	  return rsq(i2, j2) + rsq(i1-1, j1-1) - rsq(i1-1, j2) - rsq(i2, j1-1); 
	}  

};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n,m, q;
	cin>>n>>m>>q;
	vector<vi> ma(n+1, vi(m+1));
	forn(i, 1, n) forn(j, 1, m) cin>>ma[i][j];
	FenwickTree2D ft(ma);
	while(q--) {
		int t;
		cin>>t;
		if(t==1) {
			ll x, y, v;
			cin>>x>>y>>v;
			ft.update(x, y, v);
		} else {
			ll x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<ft.rsq(x1,y1,x2,y2)<<'\n';
		}
	}
	return 0;
}
