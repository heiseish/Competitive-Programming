/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
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
const int maxn = 23;
int m[maxn];
int d[maxn][maxn];
pi a[maxn];
int dp[1 << 20][maxn];
unordered_map<string, vi> temp;
int n;
int solve(int mask, int cur) {
	if (mask == (1 << n) - 1) return d[cur][0];
	if (dp[mask][cur] != 0) return dp[mask][cur];
	int &ans = dp[mask][cur] = INF;
	forn(i, 1, n) {
		if (!(mask & (1 << (i - 1)))) {
			ans = min(ans,  d[cur][i] + solve(mask | m[i], i));
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	int r, c;
	string s;
	a[0] = { 0, 0};
	forn(i,0,n) {
		cin>>r>>c>>s;
		a[i] = { r, c};
		temp[s].pb(i);
	}
	forn(i,0,n) forn(j,0,n) 
		d[i][j] = abs(a[i].st - a[j].st) + abs(a[i].nd - a[j].nd);
	m[0] = 1;
	for (auto &v : temp) {
		for (auto &k : v.nd) {
			for (auto &p : v.nd) {
				m[k] |= (1 << p);
			}
		}
	}
	cout << solve(0, 0) <<'\n';
	return 0;
}
