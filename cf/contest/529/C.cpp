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
	int n, k;
	cin >> n >> k;
	vi ans;
	forn(i, 0, 30) {
		if (n & (1 << i)) {
			ans.pb(i);
		}
	}
	if (k < ans.size()) {
		cout << "NO\n";
		exit(0);
	}
	bool can = true;
	while(ans.size() != k && can) {
		can = false;
		forn(i, 0, (int) ans.size() - 1) {
			while (ans[i] > 0 && ans.size() != k) {
				ans[i]--;
				ans.pb(ans[i]);
				can = true;
			}
		}
	}
	if (can) {
		cout << "YES\n";
		for (auto &v : ans) cout << (int) pow(2, v) << ' ';
		cout << '\n';
	} else {
		cout << "NO\n";
	}
	

	return 0;
}