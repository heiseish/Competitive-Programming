/** 
It does not do to dwell on dreams and forget to live.        
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

struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n): n(n) {
        bit.assign(n + 1, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()-1) {
        for (size_t i = 1; i <= n; i++)
            update(i, a[i]);
    }

    int query(int r) {
        int ret = INF;
        for (; r; r -=LSOne(r))
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx +=LSOne(idx))
            bit[idx] = min(bit[idx], val);
    }
};

struct S {
	int x, y, z;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<S> s(n);
	FenwickTreeMin ft(n);
	forn(i, 0, n-1) cin>>s[i].x;
	forn(i, 0, n-1)cin>>s[i].y;
	forn(i,0,n-1)cin>>s[i].z;
	sort(all(s), [](const S& lhs, const S& rhs) {
		return lhs.x<rhs.x;
	});
	int ans=0;
	forn(i, 0, n-1) {
		int next = ft.query(s[i].y-1);
		if (next >= s[i].z) ans++;
		ft.update(s[i].y, s[i].z);
	}
	
	cout<<ans<<'\n';
	return 0;
}
