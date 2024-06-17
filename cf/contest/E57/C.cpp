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

int dp[183];
vi get(int n) {
	vi ans;
	forn(i, 1, n/2) {
		if (n%i==0) ans.pb(i);
	}
	ans.pb(n);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	forn(i, 1, 179) dp[i] = INF;
	forn(i, 3, 180) {
		double smallesta = 180.0 / i;
		double next = smallesta;
		while(smallesta <= 180 - 2 * next) {
			if (smallesta == floor(smallesta) * 1.0) 
				dp[(int) floor(smallesta)] = min(i, dp[(int) floor(smallesta)]);
			smallesta+=next;

		}
	}
	int tc;
	cin >> tc;
	int degree;
	while(tc--) {
		cin >> degree;
		if (degree == 179) {
			cout << "360\n";
			continue;
		} else if (degree == 178) {
			cout << "180\n";
			continue;
		}
		cout << dp[degree] << '\n';
	}
	return 0;
}