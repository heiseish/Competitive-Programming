/** 
Hard work is worthless for those that don’t believe in themselves.
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
const int maxn = 50+ 7;
int dp[maxn][maxn];
int K[maxn][maxn];
vi A;

/**
Cutting strings with Knutt-Yao quadratic inequalities speed up
*/
int cut(int left, int right) {
	if (right == left+1) return 0;
	int &ans = dp[left][right];
	if (ans != 1007) return ans;
	else {
		int l = left + 1, r = right - 1;
		if (K[left + 1][right] != -1 && K[left][right-1] != -1) {
			l = K[left+1][right];
			r = K[left][right - 1];
		}
		int &MIN = K[left][right];
		forn(i, l, r) {
			int res = cut(left, i) + cut(i, right) + A[right] - A[left];
			if (res < ans) {
				ans = res;
				MIN = i;
			}
		}
	}
	return ans;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, n;
	scanf("%d %d", &l, &n);
	A.resize(n);
	forn(i, 0, n-1) scanf("%d", &A[i]);
	A.insert(A.begin(), 0);
	A.push_back(l);
	forn(i, 0, n+1) forn(j, 0, n+1) dp[i][j] = 1007;
	memset(K, -1, sizeof K);
	printf("%d\n", cut(0, n + 1));
	return 0;
}
