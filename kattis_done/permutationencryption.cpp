/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
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
	while(true) {
		cin >> n;
		if (n == 0) break;
		vi k(n);
		forn(i, 0, n - 1) cin >> k[i];
		cin.ignore();
		string s;
		getline(cin , s);
		int cur = 0;
		unordered_map<int, char> g;
		cout << '\'';
		while(cur < s.length()) {
			forn(i, 1, n) g[i] = cur < s.length() ? s[cur++] : ' ';
			forn(i, 0, n - 1) cout << g[k[i]];
		}
		cout << "'\n";
	}
	return 0;
}
