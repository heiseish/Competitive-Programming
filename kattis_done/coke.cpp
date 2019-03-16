/** 
Wherever someone is still thinking of you, that place is your home.        
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

const int maxn5 = 103;
const int maxn10 = 53;
const int maxc = 153;
int dp[maxc][maxn5][maxn10];
int lu[maxc][maxn5][maxn10];
int tc;
int solve(int c, int n5, int n10) {
	if (c == 0) return 0;
	if (dp[c][n5][n10] != -1 && lu[c][n5][n10] == tc) return dp[c][n5][n10];
	lu[c][n5][n10] = tc;
	int &ans = dp[c][n5][n10] = INF;
	if (n10 > 0) {
		ans = min(ans, 1 + solve(c-1, n5, n10 - 1));
		ans = min(ans,  4 + solve(c-1, n5+1, n10-1));
	}
	if (n5 >= 1) ans = min(ans, 4 + solve(c-1, n5-1, n10));
	if (n5 >= 2) ans = min(ans, 2 + solve(c-1, n5-2, n10));
	ans = min(ans, 8 + solve(c-1, n5, n10));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>tc;
	memset(dp, -1, sizeof dp);
	memset(lu, -1, sizeof lu);
	while(tc--) {
		int c, n1, n5, n10;
		cin>>c>>n1>>n5>>n10;
		cout << solve(c, n5, n10) << '\n';
	}
	return 0;
}
