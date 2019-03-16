/** 
        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x

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
const int MAX_N = 4e4 + 3;
const int NUM_A = 26;
struct Trie {
	int root = 0;
	int lastState = 1;
	struct Node {
		int nextState = 0;
		int ct = 0;
	};
	Node g[MAX_N][NUM_A];
	void addWords(string &s) {
		int prev = root;
		int ct = 0;
		int next = s[ct] - 'a';
		while(ct < s.length()) {
			g[prev][next].ct++;
			if (g[prev][next].nextState == 0)  g[prev][next].nextState = lastState++;
			prev = g[prev][next].nextState;
			ct++;
			next = s[ct] - 'a';
		}
	}

	int checkWords(string &s) {
		int prev = root;
		int ct = 0;
		int next = s[ct] - 'a';
		while(ct < s.length() - 1) {
			if (g[prev][next].nextState == 0) return 0;
			prev = g[prev][next].nextState;
			ct++;
			next = s[ct] - 'a';
		}
		return g[prev][next].ct;
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	Trie t;
	while(n--) {
		string s;
		cin >> s;
		kakimasu(t.checkWords(s));
		t.addWords(s);
	}
	return 0;
}
