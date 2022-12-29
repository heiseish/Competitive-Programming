/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x-a.x, b.y-a.y); }

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

vector<point> pts;
vector<double> ag;
int n;

double isZero(double &num) { return abs(num) < EPS; }
int getLeft(int k) {
	if (k < 0) return getLeft(n + k);
	if (isZero(ag[k])) return getLeft(k - 1);
	return k;
}

int getRight(int k) {
	if (k >= n) return getRight(k - n);
	if (isZero(ag[k])) return getRight(k + 1);
	return k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while(cin >> n && n) {
		pts.resize(n);
		ag.resize(n);
		forn(i, 0, n - 1) cin >> pts[i].x >> pts[i].y;
		forn(i, 0, n - 1) {
			if (i == 0) ag[i] = angle(pts[1], pts[0], pts[n - 1]);
			else if (i == n - 1) ag[i] = angle(pts[0], pts[n - 1], pts[n - 2]);
			else ag[i] = angle(pts[i + 1], pts[i], pts[i - 1]);
		}
		// double minGl = 0.0;
		int ct = n;
		while(ct > 3) {
			double next = PI;
			int nextIdx = -1;
			forn(i, 0, n - 1) {
				if (!isZero(ag[i]) && ag[i] < next) {
					next = ag[i];
					nextIdx = i;
				}
			}
			int left = getLeft(nextIdx - 1), right = getRight(nextIdx + 1);
			if (ag[left]-angle(pts[nextIdx], pts[left], pts[right]) < next 
				|| ag[right]-angle( pts[left], pts[right], pts[nextIdx]) < next) break;
			ag[nextIdx] = 0.0;
			ag[left]-=angle(pts[nextIdx], pts[left], pts[right]);
			ag[right]-=angle( pts[left], pts[right], pts[nextIdx]);
			// minGl = next;
			ct--;
		}
		cout << ct << ' ';
		forn(i, 0, n - 1) 
			if (!isZero(ag[i])) 
				cout << pts[i].x << ' ' << pts[i].y << ' ';
		cout << '\n';
		
	}
	return 0;
}
