/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first

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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 40 + 3;
const int maxh = 1e3 + 7;
int t;
int n;
int dp[maxn][maxh];
int d[maxn];

int solve(int c, int curH) {
    if (curH < 0) return inf; 
    if (c == n + 1) {
        if (curH == 0) return 0;
        else return inf;
    }
    if (dp[c][curH] != -1) return dp[c][curH]; 
    int& ans = dp[c][curH];
	int b = max(curH, solve(c + 1, curH + d[c]));
    int a = max(curH, solve(c + 1, curH - d[c]));
    ans = min(a, b);
    return ans;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        forn(i, 1, n) scanf("%d", &d[i]);
        int ans = solve(1, 0);
        if (ans == inf) printf("IMPOSSIBLE\n");
        else {
            string res = "";
            int c = 1;
            int ch = 0;
            while (c < n + 1) {
                if (ch - d[c] < 0) {
                    res += "U";
                    ch += d[c];
                } else if (c == n) {
                    res += "D";
                } else if (ans >= dp[c + 1][ch + d[c]]) {
                    res += "U";
                    ch += d[c];
                } else if (ans >= dp[c + 1][ch - d[c]]) {
                    res += "D";
                    ch -= d[c];
                }
                c++;
            }
            printf("%s\n", res.c_str());
        }
    }
    return 0;
}