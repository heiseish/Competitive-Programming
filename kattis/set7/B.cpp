/**
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
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
int n, t;
const int maxn = 23;
int a[maxn];
int g[maxn][maxn];
int dp[1 << 22], lu[1 << 22];
int tc = 1;
int solve(int mask) {
    if (mask == (1 << n)- 1) return 0;
    if (dp[mask] != -1 && lu[mask] == tc) return dp[mask];
    int& ans = dp[mask] = 0;
    lu[mask] = tc;
	int left = (1 << n) - 1 - mask;
	if (__builtin_popcount(left) < 3) return ans;

	vi b;
	vi c;
	while(left) {
		int p = left & -left;
		int idx = log2(p);
		b.pb(a[idx]);
		c.pb(idx);
		left-=p;
	}
	forn(i,0,sz(b)-2) {
		auto k = lower_bound(all(b), t-b[i]-b.back()) - b.begin();
		if (k == i || k == sz(b)-1) k++;
		if (k >= sz(b)-1) continue;
		int pos = 1 << c[i];
		pos |= 1 << c.back();
		pos |= 1 << c[k];
		ans = max(ans, 1 + solve(mask | pos));
	}
	
    return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	memset(lu, -1, sizeof lu);
	while(cin>>n>>t && (n || t)) {
        tc++;
        forn(i,0,n-1) cin>>a[i];
        sort(a, a+n);
        cout << solve(0) <<'\n';
	}

	return 0;
}