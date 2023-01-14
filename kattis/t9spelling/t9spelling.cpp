/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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
unordered_map<int, string> g;
unordered_map<char, string> d;
void preprocess() {
	g[2] = "abc";
	g[3] = "def";
	g[4] = "ghi";
	g[5] = "jkl";
	g[6] = "mno";
	g[7] = "pqrs";
	g[8] = "tuv";
	g[9] = "wxyz";
	g[0] = " ";
	for (auto &v : g) {
		for (int i = 1; i <= v.nd.length(); i++) {
			string t = "";
			forn(j, 1, i) t += to_string(v.st);
			d[v.nd[i - 1]] = t; 
		}
	} 
	d['A'] = "A";
}
bool isSameKey(char l, char n) {
	return d[l][0] == d[n][0];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	preprocess();
	int tc;
	cin >> tc;
	int c = 1;
	cin.ignore();
	while(tc--) {
		string s;
		getline(cin, s);
		cout << "Case #" << c++ << ": ";
		char last = 'A';
		for (auto &v : s) {
			if (isSameKey(last, v)) cout << ' ';
			cout << d[v];
			last = v;
		}
		cout << '\n';
	}
	return 0;
}
