/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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
int n, m;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &m, &n);
	vector<int> r(m), c(n);
	int sum = 0;

	forn(i, 0, m - 1) scanf("%d", &r[i]);
	forn(i, 0, n - 1) scanf("%d", &c[i]);
	bool can = true;

	forn(i, 0, m - 1) {
		sort(all(c), greater<int>());
		forn(j, 0, n - 1) {
			if (r[i] > 0 && c[j] > 0) {
				r[i]--; c[j]--;
			}
		}
		if (r[i] > 0) {
			can = false;
			break;
		}
	}
	forn(i, 0, n  - 1)
		if (c[i] > 0)
			can = false;
	if (!can) cout << "no\n";
	else cout << "yes\n";
		
		
	return 0;
}
