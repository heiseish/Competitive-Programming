/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
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
  point(double _x, double _y) : x(_x), y(_y) {} };         // user-defined

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
	int tc;
	
	cin >> tc;
	while(tc--) {
		vector<pair<string, string> > cmd;
		point start;
		vec dir = toVec(start, point(0.0, 1.0));
		int n;
		cin >> n;
		int stidx = 0;
		forn(i, 0, n - 1) {
			string f, s;
			cin >> f >> s;
			cmd.pb({f, s});
			if (s == "?") stidx = i;
		}
		
		if (cmd[stidx].st == "fd" || cmd[stidx].st == "bk") {
			for (auto &ins : cmd) {
				int num;
				if (ins.nd == "?") num = 0;
				else num = stoi(ins.nd);
				if (ins.st == "fd") {
					start = translate(start, scale(dir, num));
				} else if (ins.st == "bk") {
					vec temp = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), 180));
					start = translate(start, scale(temp, num));
				} else if (ins.st == "lt") {
					dir = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), num));
				} else {
					dir = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), 360.0 - num));
				}
			}
			kakimasu((int) round(dist(point(0, 0), start)));
		} else {
			forn(i, 0, stidx - 1) {
				pair<string, string> &ins = cmd[i];
				int num = stoi(ins.nd);
				if (ins.st == "fd") {
					start = translate(start, scale(dir, num));
				} else if (ins.st == "bk") {
					vec temp = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), 180));
					start = translate(start, scale(temp, num));
				} else if (ins.st == "lt") {
					dir = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), num));
				} else {
					dir = toVec(point(0.0, 0.0), rotate(point(dir.x, dir.y), 360.0 - num));
				}
			}
			forn(i, 0, 359) {
				point tmpSt = start;
				vec tmpDir = dir;
				forn(j, stidx, n - 1) {
					pair<string, string> &ins = cmd[j];
					int num;
					if (j == stidx) num = i;
					else num = stoi(ins.nd);

					if (ins.st == "fd") {
						tmpSt = translate(tmpSt, scale(tmpDir, num));
					} else if (ins.st == "bk") {
						vec temp = toVec(point(0.0, 0.0), rotate(point(tmpDir.x, tmpDir.y), 180));
						tmpSt = translate(tmpSt, scale(temp, num));
					} else if (ins.st == "lt") {
						tmpDir = toVec(point(0.0, 0.0), rotate(point(tmpDir.x, tmpDir.y), num));
					} else {
						tmpDir = toVec(point(0.0, 0.0), rotate(point(tmpDir.x, tmpDir.y), 360.0 - num));
					}
				}
				if (dist(point(0, 0), tmpSt) <= EPS) {
					kakimasu(i);
					break;
				}
			}
		}
	}
	return 0;
}
