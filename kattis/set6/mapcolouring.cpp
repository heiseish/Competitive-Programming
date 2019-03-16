/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
int g[maxn], vis[maxn];
int n, m;
bool can2 = true;
void dfs(int index, int color) {
	vis[index]=color;
	for(int i = 0; i < n; i++) {
		if (index == i) continue;
		if (g[index] & (1 << i)) {
			if (vis[i] == -1) dfs(i, color^1);
			else if (vis[i] == vis[index]) can2  = false;
		}
	}
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
		if (m == 0) {
			cout << "1\n";
			continue;
		}
		memset(g, 0, sizeof g);
		memset(vis, -1, sizeof vis);
		forn(i,0,n-1) g[i] |= (1 << i);
		forn(i,1,m) {
			int a, b;
			cin>>a>>b;
			g[a] |= (1 << b);
			g[b] |= (1 << a);
		}
		can2=true;
		forn(i,0,n-1) 
			if (vis[i] ==-1) 
				dfs(i, 0);
		if (can2) {
			cout << "2\n";
			continue;
		}
		int ans = 0;
		forn(i,0,(1 << n)-1) {
			vi b;
			int temp=i;
			int id=0;
			while(temp>0) {
				if (temp&1) b.pb(id);
				temp>>=1;
				id++;
			}
			bool can = true;
			for(auto &v : b) {
				for (auto &d : b) {
					if (!(g[v] & (1 << d))) {
						can = false;
						break;
					}
				}
			}
			if (can) ans = max(ans, __builtin_popcount(i));
		}
		if (ans <= 4) cout << ans<<'\n';
		else cout << "many\n";
	}
	return 0;
}
