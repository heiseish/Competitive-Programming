/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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
const int maxmask = 2003;
const int maxn = 11;
int g[maxn];
int dp[maxmask][maxn];
int n, m;
int ans=1;
void solve(int mask, int cur) {
	if (dp[mask][cur]) return;
	dp[mask][cur]++;
	if (g[cur] & (1 << 0)) ans=max(ans, __builtin_popcount(mask));
	forn(i,0,n-1) {
		if ((g[cur] & (1 << i)) && (!(mask & (1 << i)))) 
			solve(mask | (1 << i), i);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	while(cin>>n>>m) {
		memset(g, 0, sizeof g);
		memset(dp, 0, sizeof dp);
		int a, b;
		forn(i,1,m) {
			cin>>a>>b;
			g[a] |= (1 << b);
			g[b] |= (1 << a);
		}
		ans = 1;
		solve(1, 0);
		cout << ans<<'\n';
	}
	return 0;
}
