/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
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
const int maxn = 1e2 + 3;
const int maxsc = 1e3 + 3;
int n;
pair<pi, int> a[maxn];
int t[maxn];
unordered_map<int, int> dp[maxn][maxsc];
// int lu[maxn][maxsc][maxt];
int q;
int solve(int cur, int k, int tl, int sc) {
    if (cur == n || tl == 0) return sc;
	int score = max(a[cur].st.st - k * k * a[cur].st.nd, 0);
	if (score == 0 || tl < a[cur].nd) return solve(cur+1, 0, tl, sc);
    if (dp[cur][score].count(tl)) return dp[cur][score][tl];
    // lu[cur][k][tl]=q; 
    int& ans = dp[cur][score][tl] = 0;
	ans = max(ans, solve(cur, k+1, tl - a[cur].nd, sc + score));
	ans = max(ans, solve(cur+1, 0, tl, sc));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    cin>>n;
    forn(i,0,n-1) cin>>a[i].st.st>>a[i].st.nd>>a[i].nd;
    cin>>q;
    int t;
	// memset(dp, -1, sizeof dp);
    // memset(lu, -1, sizeof lu);
    while(q--) {
        cin>>t;
		cout<<solve(0,0,t,0)<<'\n';
    }
    
    return 0;
}