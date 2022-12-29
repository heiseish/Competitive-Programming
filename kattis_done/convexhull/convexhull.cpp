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
#define EPS 1e-9
#define PI acos(-1.0)

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
   return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS)); } 
  bool operator <(const point &p) const {
   return x < p.x || (abs(x-p.x) < EPS && y < p.y); } };

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };


double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x-p2.x, p1.y-p2.y); }               // return double

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }


vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x-a.x, b.y-a.y); }


bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

vector<point> CH_Andrew(vector<point> &Pts) {
  int n = Pts.size(), k = 0;
  vector<point> H(2*n);
  sort(Pts.begin(), Pts.end());        // sort the points lexicographically
  for (int i = 0; i < n; i++) {                         // build lower hull
    while (k >= 2 && ccw(H[k-2], H[k-1], Pts[i]) <= 0) k--;
    H[k++] = Pts[i];
  }
  for (int i = n-2, t = k+1; i >= 0; i--) {             // build upper hull
    while (k >= t && ccw(H[k-2], H[k-1], Pts[i]) <= 0) k--;
    H[k++] = Pts[i];
  }
  H.resize(k);
  return H;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n) {
		vector<point> Pts(n);
		forn(i, 0, n - 1) cin >> Pts[i].x >> Pts[i].y;
		vector<bool> dup(n, false);
		forn(i, 0, n - 2) if (Pts[i] == Pts[i + 1]) dup[i] = true;
		vector<point> inp;
		forn(i, 0, n - 1) if (!dup[i]) inp.pb(Pts[i]);
		if (inp.size() == 1) {
			cout << "1\n" << inp[0].x << ' ' << inp[0].y << '\n';
			continue;
		} else if (inp.size() == 2) {
			cout << "2\n";
			cout << inp[0].x << ' ' << inp[0].y << '\n';
			cout << inp[1].x << ' ' << inp[1].y << '\n';
			continue;
		}
		vector<point> ans = CH_Andrew(inp);
		cout << (int) ans.size() - 1 << '\n';
		forn(i, 0, (int) ans.size() - 2) cout << ans[i].x << ' ' << ans[i].y << '\n';

	}
	return 0;
}
