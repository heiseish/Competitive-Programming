/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
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
const int maxn = 2e2 + 7;
int track[maxn], dp[maxn];
int n;
vi a;

int LIS(int index) {
	if (index == 0) return dp[index] = 1;
	if (dp[index] != -1) return dp[index];
	int& ans = dp[index];
	forn(i, 0, index-1) {
		if (a[i] < a[index]) {
			int res = LIS(i) + 1;
			if (res > ans || (res == ans && a[track[index]] > a[i])) {
				ans = res;
				track[index] = i;
			}
		}
	}
	ans = max(1, ans);
	return ans;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d", &n) && n) {
		a.resize(n);
		forn(i, 0, n-1) scanf("%d", &a[i]);
		memset(track, -1, sizeof track);
		memset(dp, -1, sizeof dp);
		int MAX = -1;
		int s = -1;
		forn(i, 0, n-1) {
			int res = LIS(i);
			if (res > MAX || (res == MAX && a[i] < a[s])) {
				MAX = res;
				s = i;
			} 
		}
		printf("%d ", MAX);

		vi res;
		int cur = s;
		while(cur != -1) {
			res.pb(a[cur]);
			cur = track[cur];
		}
		for (int j = res.size() - 1; j >= 0;j--) printf("%d ", res[j]);
		printf("\n");
	}
	return 0;
}
