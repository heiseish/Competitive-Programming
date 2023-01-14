/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.
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
	int n;
	scanf("%d", &n);
	vpi t(n);
	forn(i, 0, n - 1) scanf("%d %d", &t[i].st, &t[i].nd);
	sort(all(t));

	vpi res;
	forn(i, 0, n - 1) {
		bool can = false;
		forn(j, 0, (int) res.size() - 1) {
			if (!(t[i].nd < res[j].st || t[i].st > res[j].nd)) {
				res[j].nd = min(res[j].nd, t[i].nd);
				res[j].st = max(res[j].st, t[i].st);
				can = true;
				break;
			}
		}
		if (!can) res.pb(t[i]);
	}
	printf("%ld\n", res.size());
	return 0;
}
