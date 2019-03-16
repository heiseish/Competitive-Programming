/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.
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
const int maxn = 10 + 3;
const int maxm = 2e3 + 7;
int dp[maxn][maxm];
int n;
vpi b(maxn);
int dist(int f, int s) {
	return abs(b[f].st - b[s].st) + abs(b[f].nd - b[s].nd);
}
int tsp(int c, int mask) {
	if (mask == (1 << (n + 1)) - 1) return dist(c, 0);
	if (dp[c][mask] != -1) return dp[c][mask];
	else {
		int& ans = dp[c][mask];
		ans = inf;
		forn(nxt, 1, n) {
			if (!(mask & (1 << nxt))) {
				ans = min(ans, dist(c, nxt) + tsp(nxt, mask | (1 << nxt)));
			}
		}
		return ans;
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(dp, -1, sizeof dp);
		int x, y;
		scanf("%d %d", &x, &y);
		pi s;
		scanf("%d %d", &s.st, &s.nd);
		scanf("%d", &n);
		b[0] = s;
		forn(i, 1, n) scanf("%d %d", &b[i].st, &b[i].nd);
		printf("%d\n", tsp(0, 1));
	}
	return 0;
}
