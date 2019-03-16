/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
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
const int MOD = 1e9 + 7;
void add(ll& a, ll b) {
	a+=b;
	if (a >= MOD) a-=MOD;
}
void deduct(ll& a, ll b) {
	a-=b;
	if (a < 0) a+=MOD;
}
const int maxn = 1e4 + 5;
const int maxw = 103;
ll dp[maxw][maxn];
int n, w, h;
ll solve(int cur, int ribbonLeft) {
	if (cur == w) return 1;
	if (dp[cur][ribbonLeft] != -1) return dp[cur][ribbonLeft];
	ll& ans = dp[cur][ribbonLeft] = 0;
	forn(i, 0, min(ribbonLeft, h)) add(ans, solve(cur+1, ribbonLeft-i));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>w>>h;
	memset(dp, -1, sizeof dp);
	ll ans = solve(0, n);
	int numequalheight = min(h, n/w) + 1;
	deduct(ans, numequalheight);
	cout << ans <<'\n';
	return 0;
}
