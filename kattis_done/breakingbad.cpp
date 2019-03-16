/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 1e5 + 7;
map<string, int> v;
map<string, vector<string> > g;
bool can = true;;
vector<string> V;

void dfs(string index, int c) {
	v[index] = c;
	for (auto i : g[index]) {
		if (!can) return;
		if (v[i] == -1)
			dfs(i, 1 - c);
		else if (v[i] == c)
			can = false;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	V.resize(n);
	forn(i, 0, n - 1) {
		cin >> V[i];
		v[V[i]] = -1;
	}
	int m;
	cin >> m;
	forn(i, 0, m - 1) {
		string a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, 0, n - 1) {
		if (!can) break;
		if (v[V[i]] == -1)
			dfs(V[i], 0);
	}
	if (!can)
		cout << "impossible\n";
	else {
		forn(i, 0, n - 1)
			if (v[V[i]] == 0)
				cout << V[i] << " ";
		cout << '\n';
		forn(i, 0, n - 1)
			if (v[V[i]] == 1)
				cout << V[i] << " ";
		cout << '\n';
	}



	return 0;
}
