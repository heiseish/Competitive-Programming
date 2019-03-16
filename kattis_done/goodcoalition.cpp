/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
const int maxn = 153;
int S[maxn], T[maxn];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
		int n;
        cin >> n;
        forn(i, 0, n - 1) cin >> S[i] >> T[i];
		double dp[maxn] = { 0.0 };
		dp[0] = 1.0;
		forn(i, 0, n - 1) {
			for (int st = 150; st >= S[i]; st--) {
				dp[st] = max(dp[st], T[i] / 100.0 * dp[st - S[i]]);
			}
		}
		double ans = 0.0;
		forn(i, 76, 150) ans = max(ans, dp[i]);
        cout << fixed << setprecision(15) << ans * 100 << '\n';
    }
    return 0;
}