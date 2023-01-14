/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.
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
const int maxn = 1e2 + 3;
int ff[maxn][maxn];
int n, m;
vector<string> b;
void fill (int i, int j, int l) {
	if (i < 0 || i >= m || j < 0 || j >= n) return;
	if (b[i][j] == '#') return;
	if (ff[i][j] == l) return;
	ff[i][j] = l;
	fill(i + 1, j, l);
	fill(i, j + 1, l);
	fill(i - 1, j, l);
	fill(i, j - 1, l);
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int Case = 1;
	while(scanf("%d %d", &m, &n) != EOF) {
		memset(ff, 0, sizeof ff);
		b.resize(m);
		forn(i, 0, m - 1) cin >> b[i];
		int ct = 1;
		forn(i, 0, m - 1) 
			forn(j, 0, n - 1)
				if (b[i][j] != '#' && ff[i][j] == 0) 
					fill(i, j, ct++);
		printf("Case %d: %d\n", Case, ct - 1);
		Case++;
	}
	return 0;
}
