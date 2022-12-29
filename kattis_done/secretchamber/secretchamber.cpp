/** 
When a man learns to love, he must bear the risk of hatred.
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

const int inf = 1 << 29;
/**
Start coding from here
*/
const int maxn = 30;
bool d[maxn][maxn] = { false };
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, n;
	scanf("%d %d", &m, &n);
	forn(i, 1, m) {
		char f, s;
		scanf(" %c %c", &f, &s);
		d[f - 'a'][s - 'a'] = true;
	}

	forn(i, 0, 29)
		d[i][i] = true;

	forn(k, 0, 29)
		forn (i, 0, 29)
			forn(j, 0, 29) {
				d[i][j] |= (d[i][k]&d[k][j]);
			}
	forn(i, 1, n) {
		string f, s;
		cin >> f >> s;
		if (f.length() != s.length()) printf("no\n");
		else {
			bool can = true;
			forn(i, 0, f.length() - 1)
				if (!d[f[i] - 'a'][s[i] - 'a']) {
					can = false;
					break;
				}
			if (!can) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}
