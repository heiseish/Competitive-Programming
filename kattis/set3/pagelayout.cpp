/** 
Wherever someone is still thinking of you, that place is your home.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
const int maxn = 1 << 20;
int dp[maxn];
unordered_map<int, vi> g;
struct paper {
	int x1, x2, y1, y2, area;
};
vector<paper> p;
int n;
int solve(int mask) {
	if (dp[mask] != -1) return dp[mask];
	int& ans = dp[mask];
	ans = 0;

	forn(i, 0, n-1) {
		if (mask & (1 << i)) continue;
		vi t;
		for (auto &v : g[i]) if (!(mask & (1 << v))) t.pb(v);
		for (auto &v : t) mask |= (1 << v);
		ans = max(ans, p[i].area + solve(mask | (1 << i)));
		for (auto &v : t) mask &= ~(1 << v);
	}

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	while(true) {
		cin>>n;
		if(n==0) break;
		memset(dp, -1, sizeof dp);
		g.clear();
		p.resize(n);
		forn(i, 0, n-1) {
			int w, h;
			cin>>w>>h>>p[i].x1>>p[i].y1;
			p[i].x2=p[i].x1+w;
			p[i].y2=p[i].y1+h;
			p[i].area = w*h;
		}
		forn(i, 0, n-1) forn(j, i+1, n-1) {
			if (p[i].x1>=p[j].x2 || p[i].x2<=p[j].x1 || p[i].y1 >= p[j].y2 || p[i].y2 <= p[j].y1) continue;
			g[i].pb(j);
			g[j].pb(i);
		}
		cout << solve(0) <<'\n';
	}
	return 0;
}
