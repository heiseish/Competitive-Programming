/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
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
const int maxa = 103;
const int maxt = 1e7+3;
int b[maxa];
unordered_map<int, int> dp[maxa];
int a, y;
int solve(int cur, int vol) {
    if (cur == a || y/ b[cur] < vol) return vol;
    if (vol > y) return -1;
    if (dp[cur].count(vol)) return dp[cur][vol];
    int& ans = dp[cur][vol] = vol;
    if (y/ b[cur] >=vol) ans = max(ans, solve(cur+1, vol * b[cur]));
    ans = max(ans, solve(cur+1, vol));
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    cin>>tc;
    // forn(i, 0, 99) dp[i].reserve(100000);
    while(tc--) {
        cin>>a>>y;
        forn(i, 0, a-1) dp[i].clear();
        forn(i, 0,a-1)cin>>b[i];
		sort(b, b+a);
        cout << solve(0,1) << '\n';
    }
    return 0;
}