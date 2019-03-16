/** 
Hard work is worthless for those that don’t believe in themselves.        
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

struct vec { double x, y;  // name: `vec' is different from STL vector
 	vec() { x = y = 0.0; }  
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x-a.x, b.y-a.y); }

vec scale(vec v, double s) {        // nonnegative s = [<1 .. 1 .. >1]
  return vec(v.x*s, v.y*s); }                   // shorter.same.longer

point translate(point p, vec v) {        // translate p according to v
  return point(p.x+v.x, p.y+v.y); }

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
  double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
  return point(p.x * cos(rad) - p.y*sin(rad),
               p.x * sin(rad) + p.y*cos(rad)); }

double dist(point p1, point p2) {                // Euclidean distance
                      // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
  return hypot(p1.x-p2.x, p1.y-p2.y); }               // return double


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	point f, s, t;
	cin >> f.x >> f.y >> s.x >> s.y >> t.x >> t.y;
	if (abs(dist(f, s) - dist(f, t)) <= EPS) swap(f, s);
	else if (abs(dist(f, t) - dist(s, t)) <= EPS) swap(s, t);
	int angle = 90;
	vec dir = toVec(f, s);
	if (translate(s, toVec(point(0, 0), rotate(point(dir.x, dir.y), angle))) != t) angle+=180;
	dir = toVec(s, t);
	point last = translate(t, toVec(point(0, 0), rotate(point(dir.x, dir.y), angle)));
	cout << (int) round(last.x) << ' ' << (int) round(last.y) << '\n';
	return 0;
}
