/** 
        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
#define LSOne(S) ((S) & -(S))
const int maxn = 3e5 + 3;
pi range[maxn];
vi g[maxn];
int c[maxn], d[maxn], rc[maxn];

class FenwickTree {              
private: vll ft; int n;        // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int _n) : n(_n) { ft.assign(n+1, 0); }    // n+1 zeroes
  ll rsq(int j) {                                     // returns RSQ(1, j)
    ll sum = 0LL; for (; j; j -= LSOne(j)) sum ^= ft[j];
    return sum; }
  ll rsq(int i, int j) { return rsq(j) ^ rsq(i-1); }  

  void update(ll i, ll v=-1) {
		ll prevcolor = rc[i];
		if (prevcolor > 50) prevcolor -= 50;
		if (v > 50) v -= 50;

		if (v == -1) {
		   for (; i <= n; i += LSOne(i)) ft[i] ^= ((1LL << prevcolor)); 
		} else if (prevcolor == 0) {
			for (; i <= n; i += LSOne(i)) ft[i] ^= (1LL << v); 
		} else {
			for (; i <= n; i += LSOne(i)) {
				ft[i] ^= (1LL << prevcolor);
				ft[i] ^= (1LL << v); 
			}
		}
	}   
};

int dfs(int v) {
	static int idx = 1;
	d[v] = idx;
	range[v].st = idx++;
	int nxt = d[v];
	for (auto &u : g[v]) {
		nxt = max(nxt, dfs(u));
	}
	range[v].nd = nxt;
	return nxt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, q;
	cin>>n>>q;
	forn(i,1,n) cin>>c[i];
	forn(i,2,n) {
		int a;
		cin>>a;
		g[a].pb(i);
	}
	dfs(1);
	FenwickTree lo(n), hi(n);
	forn(i,1,n) {
		if (c[i] <= 50) lo.update(d[i], c[i]);
		else hi.update(d[i], c[i]);
		rc[d[i]] = c[i];
	}
	while(q--) {
		int k, x;
		cin>>k>>x;
		if (k == 0) {
			cout << __builtin_popcountll(lo.rsq(range[x].st, range[x].nd)) + 
				__builtin_popcountll(hi.rsq(range[x].st, range[x].nd)) <<'\n';
		} else {
			if (k <= 50) {
				if (rc[d[x]] > 50) {
					hi.update(d[x]);
					rc[d[x]] = 0;
				}
				lo.update(d[x], k);
				rc[d[x]] = k;
			} else {
				if (rc[d[x]] <= 50) {
					lo.update(d[x]);
					rc[d[x]] = 0;
				}
				hi.update(d[x], k);
				rc[d[x]] = k;
			}
		}
	}
	return 0;
}
