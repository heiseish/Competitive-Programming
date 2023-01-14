/** 
It does not do to dwell on dreams and forget to live.
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
vector<string> b{
	"ABCD",
	"EFGH",
	"IJKL",
	"MNO."
};

int dist (char r, int idx, int jdx) {
	forn(i, 0, 3) {
		forn(j, 0, 3) {
			if (b[i][j] == r) {
				return abs(i - idx) + abs(j - jdx);
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<string> r(4);
	forn(i, 0, 3) cin >> r[i];
	int ct = 0;
	forn(i, 0, 3) {
		forn(j, 0, 3) {
			if (r[i][j] == '.') continue;
			ct += dist(r[i][j], i, j);
		}
	}
	printf("%d\n", ct);
	return 0;
}
