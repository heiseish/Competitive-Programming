/** 
People become stronger because they have things they cannot forget. That’s what you call growth.
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
int n, m;
unordered_map<int, vi> g;
vector<int> s;
// vector<bool> e;
bool can = true;
void dfs(int index, int p) {
	s[index] = p; 
	for (auto i : g[index]) {
		if (!s[i]) {
			int np = p == 1 ? 2 : 1;
			dfs(i, np);
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &n, &m);
	s.assign(n + 1, 0);
	// e.assign(n, false);
	forn(i, 1, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, 1, n) {
		if (!can) break;
		if (g[i].size() == 0) {
			can = false;
			break;
		}
		if (!s[i]) {
			dfs(i, 1);
		}
	}
	if (!can) printf("Impossible\n");
	else {
		forn(i, 1, n) {
			if (s[i] == 1) printf("pub ");
			else printf("house ");
		}
		printf("\n");
	}
	return 0;
}
