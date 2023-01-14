/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
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

double DEG_to_RAD(double d) { return d*PI / 180.0; }


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	double v, t, x, h1, h2;
	while(tc--) {
		cin >> v >> t >> x >> h1 >> h2;
		h1+=1;
		h2-=1;
		t = DEG_to_RAD(t);
		double ti = x / (v * cos(t));
		double y = v * ti * sin(t) - 0.5 * 9.81 * pow(ti, 2);
		if (y >= h1 && y <= h2) cout << "Safe\n";
		else cout << "Not Safe\n";
	}
	return 0;
}
