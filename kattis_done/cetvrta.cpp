/** 
Wherever someone is still thinking of you, that place is your home.        
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

const double EPS = 1e-6;
double DEG_to_RAD(double d) { return d*PI / 180.0; }

// struct point_i { int x, y; };    // basic raw form, minimalist mode
struct point { double x, y;     // whenever possible, work with point_i
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {} 
  bool operator < (point other) const { // override less than operator
    if (fabs(x-other.x) > EPS)                   // useful for sorting
      return x < other.x;          // first criteria , by x-coordinate
    return y < other.y; }          // second criteria, by y-coordinate
  // use EPS (1e-9) when testing equality of two floating points
  bool operator != (point other) const {
   return !(fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));};
};         // user-defined

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	unordered_map<int, int> x, y;
	forn(i, 1, 3) {
		int a, b;
		cin >> a >> b;
		x[a]++;
		y[b]++;
	}
	for (auto &v : x) if (v.nd == 1) cout << v.st;
	cout << ' ';
	for (auto &v : y) if (v.nd == 1) cout << v.st;
	cout << '\n';
	return 0;
}
