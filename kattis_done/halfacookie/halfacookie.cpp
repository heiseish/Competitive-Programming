/** 
Those who cannot acknowledge themselves will eventually fail.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x

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
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double RAD_to_DEG(double r) { return r*180.0 / PI; }


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	double r, x, y;
	while(true) {
		cin >> r >> x >> y;
		if (cin.eof()) break;
		if (hypot(x, y) > r) cout << "miss\n";
		else {
			double l = hypot(x, y);
			double angle = acos(l/r);
			double area = r * r * PI;
			double part = angle / PI * area;
			double sector = part - 0.5 * r * r * sin(angle * 2);
			cout << setprecision(10) << area - sector << ' ' << sector << '\n';
		}
	}
	return 0;
}
