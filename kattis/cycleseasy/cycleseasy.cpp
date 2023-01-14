/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.
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
const int MOD = 9901;
const int maxn = 10 + 3;
const int maxmask = 2e3 + 7;
int g[maxn][maxn];
int dp[maxn][maxmask];
int n, k;

int tsp(int c, int mask) {
	if (mask == (1 << n) - 1) {
		return 1 - g[c][1];
	}
	int &ans = dp[c][mask];
	if (dp[c][mask] != -1) return dp[c][mask];
	ans = 0;
	forn(i, 2, n) {
		if (!(mask & (1 << (i - 1))) && !g[c][i]) {
			g[c][i] = 1;
			g[i][c] = 1;
			ans += tsp(i, mask | (1 << (i - 1)));
			g[c][i] = 0;
			g[i][c] = 0;
		}
	}
	return ans;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	forn(ct, 1, t) {
		scanf("%d %d", &n, &k);
		memset(dp, -1, sizeof dp);
		memset(g, 0, sizeof g);
		forn(i, 1, k) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a][b] = 1;
			g[b][a] = 1;
		}
		printf("Case #%d: %d\n", ct, (tsp(1, 1) / 2)%MOD);
	}
	return 0;
}
