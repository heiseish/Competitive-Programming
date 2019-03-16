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
const int maxn = 1e3 + 7;
int h[maxn];
bool d[maxn] = { false };
int main() {
	int n;
	scanf("%d", &n);
	forn(i, 0, n - 1) scanf("%d", &h[i]);
	forn(i, 1, n - 2) {
		if (h[i - 1] && h[i + 1] && !h[i]) d[i] = true;
	}
	int cur = -3;
	int ct = 0;
	forn(i, 1, n - 2) {
		if (d[i] && i != cur + 2) {
			ct++;
			cur = i;
		} 
	}
	printf("%d\n", ct);
	return 0;
}
