/** 
Those who do not understand true pain can never understand true peace.
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
const int maxn = 2e3 + 7;
int memLIS[maxn], memLDS[maxn];
vi cl;
int n;
int LIS(int index) {
	if (index == n - 1) return memLIS[n - 1] = 1;
	if (memLIS[index] != -1) return memLIS[index];
	int& ans = memLIS[index];
	forn(i, index + 1, n - 1) 
		if (cl[i] > cl[index]) 
			ans = max(ans, LIS(i) + 1);
	ans = max(1, ans);
	return ans;
}

int LDS(int index) {
	if (index == n - 1) return memLDS[n - 1] = 1;
	if (memLDS[index] != -1) return memLDS[index];
	int& ans = memLDS[index];
	forn(i, index + 1, n - 1) 
		if (cl[i] < cl[index]) 
			ans = max(ans, LDS(i) + 1);
	ans = max(1, ans);
	return ans;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d", &n);
	if (!n) {
		puts("0");
		exit(0);
	}
	cl.resize(n);
	forn(i, 0, n-1) scanf("%d", &cl[i]);
	memset(memLIS, -1, sizeof memLIS);
	memset(memLDS, -1, sizeof memLDS);
	forn(i, 0, n-1) LIS(i);
	forn(i, 0, n-1) LDS(i);
	int res = 0;
	forn(i, 0, n-1) res = max(res, memLIS[i] + memLDS[i] - 1);
	printf("%d\n", res);
	return 0;
}
