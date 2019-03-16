/** 
When a man learns to love, he must bear the risk of hatred.        
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define debug(x) cout<<#x<<" --> "<<x<<'\n';

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxc = 203;
const int maxl = 1005;
int g[maxc][maxc];
int dp[maxl][maxl];
vector<pair<pi, int> > lec;
int c, l, t, cl, sl;
int solve(int curl, int prevl=1003) {
	// debug(curl);
	// debug(prevl);
    if (curl == l) return 0;
    if (dp[curl][prevl] != -1) return dp[curl][prevl];
    int& ans = dp[curl][prevl] = 0;
    if (prevl==1003 || 
		lec[prevl].st.nd + g[lec[prevl].nd][lec[curl].nd] <= lec[curl].st.st)
            ans = max(ans, 1 + solve(curl + 1, curl));
	ans = max(ans, solve(curl+1, prevl));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>c>>l;
        memset(g, 0, sizeof g);
        memset(dp, -1, sizeof dp);
        int a, b, tt;
        forn(i, 1, c * (c-1)/2) {
            cin>>a>>b>>tt;
            g[a][b] = tt;
            g[b][a] = tt;
        }
        forn(k, 0, c-1) forn(i,0,c-1) forn(j,0,c-1)
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        lec.resize(l);
        forn(i, 0, l-1) cin>>lec[i].nd>>lec[i].st.st >>lec[i].st.nd;
        sort(all(lec));
        cout << solve(0) << '\n';

    }
    return 0;
}