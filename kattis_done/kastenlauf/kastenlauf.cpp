/** 
you can do it too because you are not a failure like me.
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
bool d[maxn][maxn] = { false };
int dist(pi f, pi s) {
	return abs(f.st - s.st) + abs(f.nd - s.nd);
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vpi l(n + 2);
		forn(i, 0, n + 1) scanf("%d %d", &l[i].st, &l[i].nd);
		forn(i, 0, n + 1)
			forn(j, 0, n + 1)
				d[i][j] = (dist(l[i], l[j]) <= 50 * 20);
		forn(k, 0, n + 1)
			forn(i, 0, n + 1)
				forn(j, 0, n+ 1)
					d[i][j] |= (d[i][k]&d[k][j]);
		if (d[0][n+1]) printf("happy\n");
		else printf("sad\n");

	}
	return 0;
}
