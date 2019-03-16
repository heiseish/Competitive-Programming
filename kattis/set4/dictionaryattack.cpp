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
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
bool compare(string &lhs, string &rhs) {
	forn(i, 0, sz(lhs) - 1) {
		if (i >= sz(rhs)) return false;
		if (lhs[i] == '*' || rhs[i] == '*' || lhs[i] == rhs[i]) continue;
		return lhs[i] < rhs[i];
	}
	return sz(lhs) < sz(rhs);
}

bool equal(string &lhs, string &rhs) {
	if (sz(lhs) != sz(rhs)) return false;
	forn(i, 0, sz(lhs) - 1) {
		if (lhs[i] == '*' || rhs[i] == '*' || lhs[i] == rhs[i]) continue;
		if (lhs[i] != rhs[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<vector<string> > g(4), temp(4);
	forn(j, 1, n) {
		string s;
		cin>>s;
		forn(i, 0, 3) {
			temp[i].clear();
			if (i==0) {
				temp[i].pb(s);
				g[i].pb(s);
			} else {
				for (auto ss : temp[i-1]) {
					forn(k, 0, sz(ss)-2) {
						string r(ss);
						swap(r[k], r[k+1]);
						temp[i].pb(r);
						g[i].pb(r);
					}
				}
			}
		}
	}
	forn(i, 0, 3) {
		sort(all(g[i]));
		UNIQUE(g[i]);
	}
	while(true) {
		string s;
		cin>>s;
		string t = s;
		if (cin.eof()) break;
		int ct = 0;
		for (auto &ch : t) {
			if (isdigit(ch)) {
				ch = '*';
				ct++;
			}
		}
		if (ct > 3) cout << s << '\n';
		else {
			bool can = false;
			forn(i, 0, 3-ct) {
				// int lo = 0, hi = sz(g[i]);
				// while(lo + 1 < hi) {
				// 	int mid =(lo + hi)>>1;
				// 	if (!compare(t, g[i][mid])) lo = mid;
				// 	else hi = mid;
				// }
				// debug(t);
				// debug(g[i][lo]);
				for (auto &z : g[i])
				if (equal(t, z)) {
					can = true;
					break;
				}
			}
			if (!can) cout << s << '\n';
		}
	}
	return 0;
}
