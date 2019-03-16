/** 
Life is short so it will be appreciated. We live to our fullest due to that.        
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
struct Rec{
	int x1, y1, x2, y2;
};
struct Circle{
	int x, y, r;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m, n;
	cin >> m;
	vector<Rec> r;
	vector<Circle> c;
	while(m--) {
		string name;
		cin >> name;
		if (name == "rectangle") {
			Rec t;
			cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
			r.pb(t);
		} else {
			Circle t;
			cin >> t.x >> t.y >> t.r;
			c.pb(t);
		}
	}
	cin >> n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		int ct = 0;
		for (auto &rr : r) {
			if (x <= rr.x2 && x >= rr.x1 && y <= rr.y2 && y>=rr.y1) ct++;
		}
		for (auto &cc : c) {
			int ds = pow(cc.x - x, 2) + pow(cc.y - y, 2);
			if (ds <= cc.r * cc.r) ct++;
		}
		cout << ct << '\n';
	}
	return 0;
}
