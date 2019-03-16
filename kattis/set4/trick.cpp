/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

const int INF = 1 << 30;
/**
Start coding from here
*/
const double EPS = 1e-8;
void toFrac(double c, int&a, int&b) {
	a = 0, b = 1;
	while(abs(c - round(c)) > EPS) {
		b *= 10;
		c *= 10;
	}
	a = (int) round(c);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// #ifdef LOCAL_PROJECT
	// 	freopen("input.txt","r",stdin);
	// #endif
	double x;
	cin>>x;
	if (x >= 10.0) {
		cout << "No solution\n";
		return 0;
	} 
	int c, d;
	toFrac(x, c, d);
	int e = 10 * d - c;
	bool can = false;
	forn(i, 0, 7) {
		double t = (1.0 * pow(10.0, i) * c - d) / e;
		if (t < 0) continue;
		forn(j, 1, 9) {
			double b = t * j;
			if (abs(b - round(b)) > EPS) continue;
			int fin = (int) round(b);
			if (fin >= pow(10, i)) continue;
			if (i >= 1 && fin < pow(10, i-1)) continue;
			can = true;
			if (fin != 0) cout << j << fin << '\n';
			else cout << j << '\n';
		}
	}
	if (!can) cout << "No solution\n";
	return 0;
}
