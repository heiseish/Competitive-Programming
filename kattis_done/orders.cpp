/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion
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
const int maxsum = 3e4 + 7;
const int maxn = 1e3 + 3;
ll dp[maxn][maxsum];
int m[maxn];
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	forn(i, 1, n) scanf("%d", &m[i]);
	forn(i, 0, maxsum - 1) dp[0][i] = 0L;
	forn(i, 0, n) dp[i][0] = 1L;
	forn(i, 1, n) 
		forn(j, 1, maxsum - 1) {
			if (j < m[i]) dp[i][j] = dp[i-1][j];
			else {
				dp[i][j] = dp[i-1][j];
				forn(k, 1, j/m[i]) dp[i][j] += dp[i-1][j - k * m[i]];
			}
				
		}
	int q;
	scanf("%d", &q);
	while(q--) {
		int c;
		scanf("%d", &c);
		if (dp[n][c] == 0) printf("Impossible\n");
		else if (dp[n][c] > 1) printf("Ambiguous\n");
		else {
			vi sol;
			int res = c, s = n;
			while (s > 0 && res > 0) {
				if (!dp[s - 1][res]) {
					forn(k, 1, res/m[s]) {
						if (dp[s - 1][res - k*m[s]]) {
							forn(i, 1, k) {
								sol.pb(s);
								res-=m[s];
							}
							break;
						}
					}
				}
				s--;
			}
			for (int i = (int) sol.size() - 1; i >=0;i--) printf("%d ", sol[i]);
			printf("\n");
		}
	}
	return 0;
}
