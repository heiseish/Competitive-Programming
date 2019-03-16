/** 
it is foolish to fear what we have to see and know”
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
const int maxn = 1e4 + 7;
int e[maxn];
int n, m, l;
unordered_map<int, vi> g;
int ct = 0;
void dfs(int index) {
	e[index] = 1;
	ct++;
	for (auto i : g[index]) {
		if (!e[i]) dfs(i);
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(e, 0, sizeof e);
		ct = 0;
		scanf("%d %d %d", &n, &m, &l);
		forn(i, 1, m) {
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].pb(b);
		}
		forn(i, 1, l) {
			int temp;
			scanf("%d", &temp);
			if (!e[temp]) dfs(temp);
		}
		printf("%d\n", ct);
		g.clear();
	}
	return 0;
}
