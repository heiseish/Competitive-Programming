/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
const int maxn = 1e3 + 2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vpi o(n), p(n);
	map<pi, vpi> ans;
	forn(i, 0, n - 1) cin >> o[i].st >> o[i].nd;
	forn(i, 0, n - 1) cin >> p[i].st >> p[i].nd;
	forn(i, 0, n - 1) forn(j, 0, n - 1) {
		ans[{o[i].st + p[j].st, o[i].nd + p[j].nd}].pb({i, j});
	}
	for (auto &v : ans) {
		unordered_map<int, int> checkf, checks;
		if (v.nd.size() >= n) {
			// debug(v.st.st);
			// debug(v.st.nd);
			for (auto &s : v.nd) {
				checkf[s.st]++;
				checks[s.nd]++;
			}
			// debug(checkf.size());
			// debug(checks.size());
			if (checkf.size() == n && checks.size() == n) {
				cout << v.st.st << ' ' << v.st.nd << '\n';
				exit(0);
			}
		}
	}
	return 0;
}
