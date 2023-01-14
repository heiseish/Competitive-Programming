/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.        
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
	unordered_map<char, string> d;
	d['a'] = "@";
	d['b'] = "8";
	d['c'] = "(";
	d['d'] = "|)";
	d['e'] = "3";
	d['f'] = "#";
	d['g'] = "6";
	d['h'] = "[-]";
	d['i'] = "|";
	d['j'] = "_|";
	d['k'] = "|<";
	d['l'] = "1";
	d['m'] = "[]\\/[]";
	d['n'] = "[]\\[]";
	d['o'] = "0";
	d['p'] = "|D";
	d['q'] = "(,)";
	d['r'] = "|Z";
	d['s'] = "$";
	d['t'] = "']['";
	d['u'] = "|_|";
	d['v'] = "\\/";
	d['w'] = "\\/\\/";
	d['x'] = "}{";
	d['y'] = "`/";
	d['z'] = "2";
	string n;
	getline(cin, n);
	for (auto &v : n) {
		if (d.find(tolower(v)) == d.end()) cout << v;
		else cout << d[tolower(v)];
	}
	cout << '\n';
	return 0;
}
