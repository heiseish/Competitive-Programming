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
const int maxn = 8 + 3;
char b[maxn][maxn];
// int r[maxn];
bitset<16> r, c, rdia, ldia;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	const int n = 8;
	forn(i, 0, n - 1) scanf("%s", b[i]);
	int ct = 0;
	forn(j, 0, 7) {
		forn(i, 0, 7) {
			if (b[i][j] == '*' && !c[j]) {
				if (r[i] || rdia[i - j + n - 1] || ldia[i + j]) {
					printf("invalid\n");
					exit(0);
				}
				c[j] = r[i] = rdia[i - j + n - 1] = ldia[i + j] = true;
				ct++;
			} else if (b[i][j] == '*' && c[j]) {
				printf("invalid\n");
				exit(0);
			}
		}
	}

	if (ct == 8 ) printf("valid\n");
	else printf("invalid\n");
	return 0;
}
