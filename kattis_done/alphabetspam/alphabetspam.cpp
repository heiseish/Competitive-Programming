/** 
When a man learns to love, he must bear the risk of hatred.        
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
	string s;
	cin >> s;
	int n = s.length();
	int ws = 0, lc = 0, uc = 0, sb = 0;
	for (auto &ch : s) {
		if (ch == '_') ws++;
		else if (isalpha(ch)) {
			if (ch >= 'a') lc++;
			else uc++;
		} else sb++;
	}
	cout << fixed << setprecision(15);
	double dws = 1.0 * ws / n, dlc = 1.0 * lc / n, duc = 1.0 * uc / n, dsb = 1.0 * sb / n;
	cout << dws << '\n' << dlc << '\n' << duc << '\n' << dsb << '\n';
	return 0;
}
