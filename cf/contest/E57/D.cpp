/** 
Those who cannot acknowledge themselves will eventually fail.        
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

const ll INF = 1L << 60;
/**
Start coding from here
*/
const int maxn = 1e5 + 3;
ll dp[maxn][4];
int a[maxn];
int n;
string s;
string t = "hard";
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	forn(i, 0, n - 1) forn(j, 0, 3) dp[i][j] = INF;
	forn(i, 0, n - 1) cin >> a[i];
	for (int  i = n - 1; i >= 0 ; i--) {
		for (int j = 0; j <= 3; j++) {
			if (s[i] != t[j]) dp[i][j] = (i == n - 1 ? 0 : dp[i + 1][j]);
			else if (j < 3) dp[i][j] = min(dp[i + 1][j + 1], a[i] + dp[i + 1][j]);
			else dp[i][j] = a[i] + dp[i + 1][j];
		}
	}
	cout << dp[0][0] << '\n';
	return 0;
}
