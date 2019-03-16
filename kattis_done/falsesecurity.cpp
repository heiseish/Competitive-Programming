/** 
Those who do not understand true pain can never understand true peace.        
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
unordered_map<string, char> rg;
void preprocess() {
	g['A'] = ".-";
	g['B'] = "-...";
	g['C'] = "-.-.";
	g['D'] = "-..";
	g['E'] = ".";
	g['F'] = "..-.";
	g['G'] = "--.";
	g['H'] = "....";
	g['I'] = "..";
	g['J'] = ".---";
	g['K'] = "-.-";
	g['L'] = ".-..";
	g['M'] = "--";
	g['N'] = "-.";
	g['O'] = "---";
	g['P'] = ".--.";
	g['Q'] = "--.-";
	g['R'] = ".-.";
	g['S'] = "...";
	g['T'] = "-";
	g['U'] = "..-";
	g['V'] = "...-";
	g['W'] = ".--";
	g['X'] = "-..-";
	g['Y'] = "-.--";
	g['Z'] = "--..";
	g['_'] = "..--";
	g[','] = ".-.-";
	g['.'] = "---.";
	g['?'] = "----";

	for (auto &v : g)
		rg[v.nd] = v.st;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	preprocess();
	string s;
	while (true) {
		cin >> s;
		if (cin.eof()) break;
		vi k;
		string morse = "";
		for (auto &v : s) {
			k.pb(g[v].length());
			morse += g[v];
		}
		reverse(all(k));
		int cur = 0;
		for (auto &v : k) {
			cout << rg[morse.substr(cur, v)];
			cur+= v;
		}
		cout << '\n';

	}
	return 0;
}
