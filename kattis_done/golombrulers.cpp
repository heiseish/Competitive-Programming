/** 
When a man learns to love, he must bear the risk of hatred.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
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
	string m;
	while(getline(cin, m) && !cin.eof()) {
		int n;
		istringstream is(m);
		vector<int> a;
		int MAX = -1;
		while( is >> n ) {
			a.pb(n);
			if (n > MAX) MAX = n;
		}
		vector<bool> b(MAX + 1, false);
		bool can = true;

		forn(i, 0, a.size() - 1) {
			forn(j, i + 1, a.size() - 1) {
				if (b[abs(a[i] - a[j])]) can = false;
				else b[abs(a[i] - a[j])] = true;
			}
		}

		if (!can) {
			printf("not a ruler\n");
			continue;
		}

		bool perf = true;
		forn(i, 1, b.size() - 1) {
			if (!b[i]) {
				if (perf) {
					perf = false;
					printf("missing %d ", i);
				} else printf("%d ", i);
			}
		}
		if (perf) printf("perfect\n");
		else printf("\n");
	
	}
	return 0;
}
