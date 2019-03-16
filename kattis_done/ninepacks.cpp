/** 
It does not do to dwell on dreams and forget to live.
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

const int inf = 1e5 + 7;
/**
Start coding from here
*/
const int maxn = 1e2 + 5;
const int maxnum = 1e5 + 1;
int memo1[maxn][maxnum], memo2[maxn][maxnum];
int hh[maxn];
int bb[maxn];
int h, b;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d", &h);
	forn(i, 1, h) scanf("%d", &hh[i]);
	scanf("%d", &b);
	forn(i, 1, b) scanf("%d", &bb[i]);
	forn(i, 0, maxnum - 1) {
		memo1[0][i] = inf;
		memo2[0][i] = inf;
	}
	forn(i, 0, b) memo1[i][0] = 1;
	forn(i, 0, h) memo2[i][0] = 1;
	forn(i, 1, b) 
		forn(j, 1, maxnum - 1) {
			if (j < bb[i]) memo1[i][j] = memo1[i-1][j];
			else memo1[i][j] = min(memo1[i-1][j], 1 + memo1[i-1][j-bb[i]]);
		}
	forn(i, 1, h) 
		forn(j, 1, maxnum - 1) {
			if (j < hh[i]) memo2[i][j] = memo2[i-1][j];
			else memo2[i][j] = min(memo2[i-1][j], 1 + memo2[i-1][j-hh[i]]);
		}
	int MIN = inf;
	forn(i, 1, maxnum - 1) MIN = min(MIN, memo1[b][i] + memo2[h][i]);
	if (MIN == inf) printf("impossible\n");
	else printf("%d\n", MIN - 2);
	return 0;
}
