/** 
you can do it too because you are not a failure like me.
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
const int maxn = 7;
char b[maxn][maxn];
int ct = 0;

void check(int i, int j) {
	if (b[i][j] == '.') return;
	if (i >= 2 && b[i - 1][j] == 'o' && b[i - 2][j] == '.') ct++;
	if (i <=4 && b[i + 1][j] == 'o' && b[i + 2][j] == '.') ct++;
	if (j >= 2 && b[i][j - 1] == 'o' && b[i][j - 2] == '.') ct++;
	if (j <=4 && b[i][j + 1] == 'o' && b[i][j + 2] == '.') ct++;
}

void solve() {
	forn(i, 0, 6) {
		if (i < 2 || i > 4) {
			forn(j, 2, 4) check(i, j);
		} else {
			forn(j, 0, 6) check(i, j);
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	forn(i, 0, 6) {
		string temp;
		cin >> temp;
		if (i < 2 || i > 4) {
			forn(j, 0, 2) b[i][2 + j] = temp[j];
		} else {
			forn(j, 0, 6) b[i][j] = temp[j];
		}
	}
	solve();
	printf("%d\n", ct);
	return 0;
}
