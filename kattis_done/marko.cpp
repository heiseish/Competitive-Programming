/** 
Hard work is worthless for those that don’t believe in themselves.        
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

unordered_map<char, string> g;
unordered_map<char, char> d;
void preprocess() {
	g['2'] = "abc";
	g['3'] = "def";
	g['4'] = "ghi";
	g['5'] = "jkl";
	g['6'] = "mno";
	g['7'] = "pqrs";
	g['8'] = "tuv";
	g['9'] = "wxyz";
	for (auto &v : g) {
		for (int i = 1; i <= v.nd.length(); i++) {
			d[v.nd[i - 1]] = v.st; 
		}
	} 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	preprocess();
	int n;
	cin >> n;
	vector<string> in(n);
	forn(i, 0, n - 1) cin >> in[i];
	string k;
	cin >> k;
	int ct = 0;
	forn(i, 0, n - 1) {
		if (in[i].length() != k.length()) continue;
		bool can = true;
		forn(j, 0, in[i].length() - 1) {
			if (d[in[i][j]] != k[j]) {
				can = false;
				break;
			}
		}
		if (can) ct++;
	}
	cout << ct << '\n';
	return 0;
}
