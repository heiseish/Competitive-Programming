/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.
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
const int maxn = 12;

bool valid(int i, int j, int k, vector<string> s) {
	forn(m, 0, 3) {
		if (s[i][m] == s[j][m] && s[i][m] == s[k][m] && s[k][m] == s[j][m]) continue;
		if (s[i][m] != s[j][m] && s[i][m] != s[k][m] && s[k][m] != s[j][m]) continue;
		return false;
	}
	return true;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<string> s(maxn + 3);
	forn(i, 1, maxn) cin >> s[i];
	bool found = false;
	forn(i, 1, maxn) {
		forn(j, i + 1, maxn) {
			forn(k, j + 1, maxn) {
				if (valid(i, j, k, s)) {
						printf("%d %d %d\n", i, j, k);
						found = true;
					}
			}
		}
	}
	if (!found) printf("no sets\n");

	return 0;
}
