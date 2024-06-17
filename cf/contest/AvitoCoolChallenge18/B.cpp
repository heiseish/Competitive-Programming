/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<int> d(n);
	unordered_map<int, int> g;
	unordered_map<int, vi> temp;
	forn(i, 0, n - 1) {
		cin >> d[i];
		d[i] = n - d[i];
		g[d[i]]++;
		temp[d[i]].pb(i);
	}
	bool can = true;
	int cur = 1;
	for (auto &v : g) {
		if (v.nd % v.st != 0) {
			can = false;
			break;
		}
		int count = 0;
		for (auto &idx : temp[v.st]) {
			if (count ==  v.st) {
				cur++;
				count = 0;
			}
			d[idx] = cur;
			count++;
		}
		cur++;
	}
	if (!can) cout << "Impossible\n";
	else {
		cout << "Possible\n";
		forn(i, 0, n - 1) {
			cout << d[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
