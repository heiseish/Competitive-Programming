/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
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

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 103;
const int maxm = 2e4 + 3;
int dp[3][maxn][maxm];
int a[maxn];
int n, m;
int solve(int state, int cur, int curm, int prev) {
	if (cur == n) return 0;
	if (dp[state][cur][curm] != -1) return dp[state][cur][curm];
	int& ans = dp[state][cur][curm] = 0;
	if (state == 0) {
		ans = max(ans, min(a[cur], curm) + solve(0, cur+1, 2 * curm/3, curm));
		ans = max(ans, solve(1, cur+1, prev, prev));
	} else if (state == 1) {
		ans = max(ans, min(a[cur], prev) + solve(0, cur+1, 2 * curm/3, curm));
		ans = max(ans, solve(2, cur+1, m, curm));
	} else {
		ans = max(ans, min(a[cur], curm) + solve(0, cur+1, 2 * curm/3, curm));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>m;
	forn(i, 0, n-1)cin>>a[i];
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0, m, m) << '\n';
	return 0;
}
