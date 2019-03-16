/** 
Those who do not understand true pain can never understand true peace.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	// int cc, n;
	// cin >> cc >> n;
	// vector<int> a(n);
	// for (int i = 0; i < cc; i++) {
	// 	int x;
	// 	cin >> x;
	// 	x--;
	// 	a[x]++;
	// }
	// vector<vector<int>> dp(3, vector<int>(3, 0));
	// for (int c : a) {
	// 	debug(c);
	// 	vector<vector<int>> new_dp(3, vector<int>(3, 0));
	// 	for (int x = 0; x < 3; x++) {
	// 		for (int y = 0; y < 3; y++) {
	// 			for (int z = 0; z < 3; z++) {
	// 				if (x + y + z <= c) {
	// 					new_dp[y][z] = max(new_dp[y][z], dp[x][y] + z + (c - x - y - z) / 3);
	// 				}
	// 			}
	// 		}
	// 	}
	// 	swap(dp, new_dp);
	// }
	// cout << dp[0][0] << '\n';
	const int N = (int)1e6 + 77;
	int a[N];
	int dp[N][3][3];
	int n, m;

	scanf("%d%d", &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		a[x + 1]++;
	}
	m += 10;
	
	for (int i = 0; i < m - 2; i++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++) {
				int p = a[i] - x - y;
				int q = a[i + 1] - y;
				int r = a[i + 2];
				for (int z = 0; z < 3; z++) {
					if (p < z || q < z || r < z) continue;
					dp[i + 1][y][z] = max(dp[i + 1][y][z], dp[i][x][y] + z + (p - z) / 3);
				}
			}
	int ans = 0;
	for (int i = 0; i <= m; i++)
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				ans = max(ans, dp[i][x][y]);
	printf("%d\n", ans);
	return 0;
}
