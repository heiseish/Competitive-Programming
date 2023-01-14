/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.
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

const double inf = 1e3 + 3.0;
/**
Start coding from here
*/
const int maxn = 2e2 + 3;
double g[maxn][maxn];
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c;
	while(scanf("%d", &c) && c) {
		unordered_map<string, int> m;
		int ct = 0;
		forn(i, 1, c) {
			string temp;
			cin >> temp;
			m[temp] = ct++;
		}
		forn(i, 0, c - 1)
			forn(j, 0, c - 1)
				g[i][j] = (i == j) ? 0.0 : inf;
		int e;
		scanf("%d", &e);
		forn(i, 0, e - 1) {
			string f, s;
			cin >> f >> s;
			int num, de;
			scanf("%d:%d", &num, &de);
			g[m[f]][m[s]] = log(1.0 * num / de);
		}
		forn(k, 0, c - 1)
			forn(i, 0, c - 1)
				forn(j, 0, c - 1)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		bool is  = false;
		
		forn(i, 0, c - 1) 
			if (g[i][i] < 0) {
				// debug(g[i][i]);
				is = true;
				break;
			}
		if (is) printf("Arbitrage\n");
		else printf("Ok\n");
	}

	return 0;
}
