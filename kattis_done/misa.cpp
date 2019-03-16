/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
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
int r, s;
const int maxn = 50 + 7;
char m[maxn][maxn];
int MAX = 0;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &r, &s);
	forn(i, 0, r-1) {
		scanf("%s", m[i]);
	}
	int a = 0, b = 0;
	forn(i, 0, r-1) {
		forn(j, 0, s-1){
			if (m[i][j] != '.') continue;
			int ct = 0;
			forn(k, max(0, i - 1), min(r - 1, i + 1)) {
				forn(l, max(0, j - 1), min(s - 1, j + 1)) {
					if (m[k][l] == 'o') ct++;
				}
			}
			if (ct > MAX) {
				MAX = ct;
				a = i;
				b = j;
			}
		}
	}
	// printf("%d\n", MAX);
	if (MAX != 0) {
		m[a][b] = 'o';
	}
	int ct = 0;
	forn(i, 0, r-1) {
		forn(j, 0, s-1){
			if (m[i][j] == '.') continue;
			if (j < s - 1 && m[i][j + 1] == 'o') ct++;
			if (i < r - 1) {
				if (j > 0 && m[i + 1][j - 1] == 'o') ct++;
				if (m[i + 1][j] == 'o') ct++;
				if (j < s - 1 && m[i + 1][j + 1] == 'o') ct++;
			} 
		}
	}
	printf("%d\n", ct);
	return 0;
}
