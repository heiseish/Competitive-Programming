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

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0;i < m;i ++) {
			int a, b;
			scanf("%d %d", &a, &b);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}
