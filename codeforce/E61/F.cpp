/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
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
const int maxn = 505;
int dp[maxn][maxn];
string s;
int n;
int solve(int l, int r) {
	
	if (l > r) return 0;
	if (l == r) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	int& ans = dp[l][r];
	ans = 1 + solve(l + 1, r);
	forn(i,l+1,r) {
		if (s[i] == s[l])
			ans = min(ans, solve(l + 1, i-1) + solve(i, r));
	}
	debug(l);
	debug(r);
	debug(ans);
	return ans;
	
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>s;
	memset(dp, -1, sizeof dp);
	cout << solve(0, n-1) <<'\n';
	return 0;
}
