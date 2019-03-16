/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 17;
int vis[maxn], haha[maxn];
unordered_map<int, vi> g;
int n, m;

bool dfs(int index, int color, int numcol) {
	haha[index]++;
	for (auto &v : g[index]) {
		if (vis[v] == color) {
			return false;
		}
	}
	vis[index]=color;
	bool flag = true;
	bool can = true;
	for (auto &v : g[index]) {
		if (vis[v] == -1) {
			bool really= false;
			forn(j,1,numcol) {
				if (j == color) continue;
				really |= dfs(v, j, numcol) ;
				if (really) break;
			}
			can &= really;
			flag = false;
		}
	}
	vis[index]=-1;
	if(flag || can) return true;
	return false;
}
bool solve(int numclr) {
	memset(vis, -1, sizeof vis);
	memset(haha, 0, sizeof haha);
	int can = 1;
	forn(i,0,n-1) {
		if (haha[i] == 0) 
			can &= dfs(i, 1, numclr);
		if (!can) return false;
	}
	return can;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		cin>>n>>m;
		g.clear();
		forn(i,1,m) {
			int a, b;
			cin>>a>>b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int ans = -1;
		forn(i,1,4) {
			bool can = solve(i);
			if (can) {
				ans = i;
				break;
			}
		}
		if (ans != -1) cout << ans<<'\n';
		else cout << "many\n";
	}
	return 0;
}
