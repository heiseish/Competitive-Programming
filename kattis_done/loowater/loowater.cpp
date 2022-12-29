/** 
you can do it too because you are not a failure like me.
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

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	while(scanf("%d %d", &n, &m) && (n && m)) {
		vector<int> d(n), k(m);
		forn(i, 0, n - 1) scanf("%d", &d[i]);
		forn(i, 0, m - 1) scanf("%d", &k[i]);
		sort(all(d));
		sort(all(k));
		int i = 0, j = 0, ct = 0;
		while(i < n && j < m) {
			if (d[i] <= k[j]) {
				ct+=k[j];
				i++;j++;
			} else j++;
		}
		if (i == n) printf("%d\n", ct);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
