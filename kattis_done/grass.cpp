/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
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
typedef vector<ld> vd;
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
ld n, l, w;
const ld EPS = 1e-5;
bool notEqual(ld lhs, ld rhs) {
	return abs(lhs - rhs) > EPS;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true) {
		cin >> n >> l >> w;
		if (cin.eof()) break;
		vector<pair<ld, ld> > ans;
		forn(i, 0, n - 1) {
			ld d, r;
			cin >> d >> r;
			if (r <= w/2) continue;
			ld ro = sqrt(pow(r, 2) - pow(0.5 * w, 2));
			ld lo = max<ld>(0.0, d - ro), hi = min<ld>(d + ro, l);
			ans.pb({lo, hi});
		}
		sort(all(ans));
		vector<pair<ld, ld> > res;
		res.pb({0.0, 0.0});
		ld le = 0.0;
		bool can = true;
		for (auto &p : ans) {
			auto [lo, hi] = p;
			if (notEqual(lo, le) && lo > le) {
				can = false;
				break;
			}
			while(res.size() >= 2 && res[res.size() - 2].nd >= lo && res.back().nd <= hi) res.pop_back();
			if (res.back().nd < hi && res.back().nd < l) res.pb(p);
			le = max(le, hi);
		}
		if (!can || (notEqual(le, l) && le < l)) cout << "-1\n";
		else cout << (int) res.size() - 1 << '\n';

	}
	return 0;
}
