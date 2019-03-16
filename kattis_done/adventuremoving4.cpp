/** 
Those who do not understand true pain can never understand true peace.        
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
const int maxd = 1e2 + 5;
const int maxg = 203;
ll dp[maxg][maxd];
vpi c;
int n;
int d;
ll solve(int gas, int cur) {
	if (gas < 0) return INF;
	if (cur == n-1) {
		if (gas >= 100) return 0;
		else return INF;
	} 
	if (dp[gas][cur] != -1) return dp[gas][cur];
	ll& ans = dp[gas][cur] = INF;
	int dist = c[cur+1].st - c[cur].st;
	for(int i = 200;i>=gas;i--)
		ans = min(ans, (i - gas) * c[cur].nd + solve(i - dist, cur+1));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>d;
	memset(dp, -1, sizeof dp);
	int dc, s;
	while(cin >> dc >> s) c.pb({dc, s});
	c.pb({d, 0});
	n = sz(c);
	int ans = solve(100 - c[0].st, 0);
	if (ans == INF) cout << "Impossible\n";
	else cout<<ans <<'\n';
	return 0;
}
