#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())

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
const int maxn = 2e5 + 7;
int s[maxn];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	map<int, int> dp;
	forn(i, 0, n - 1) {
		scanf("%d", &s[i]);
		dp[s[i]]++;
	}
	vpi arr;
	for (auto i : dp) arr.push_back({ i.second, i.first});

	int l = 0, r = n + 1;
	while (l + 1 < r) {
		int m = (l + r) >> 1;
		int c = 0;
		forn(i, 0, arr.size() - 1) {
			c += arr[i].first / m;
		}
		if (c >= k) l = m;
		else r = m;
	}
	vi res;
	forn(i, 0, arr.size() - 1) {
		forn(j, 1, arr[i].first / l) {
			res.push_back(arr[i].second);
		}
	}
	forn(i, 0, k - 1) printf("%d ", res[i]);
	return 0;
}
