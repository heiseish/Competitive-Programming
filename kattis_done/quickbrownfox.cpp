/** 
you can do it too because you are not a failure like me.        
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
	int tc;
	cin >> tc;
	cin.ignore();
	while(tc--) {
		string s;
		getline(cin, s);
		unordered_map<char, int> g;
		for (auto &v : s) g[tolower(v)]++;
		vector<char> m;
		forn(i, 0, 25) {
			if (!g['a' + i]) m.pb('a' + i);
		}
		if (m.empty()) cout << "pangram\n";
		else {
			cout << "missing ";
			for (auto &v : m) cout << v;
			cout << '\n';
		}
	}
	return 0;
}
