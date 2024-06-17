/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
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
const int MAX_N = 503;
const int MAX_K = 12;
const int MAX_F = 1e5 + 3;
int f[MAX_F], h[MAX_K], c[MAX_F];
int dp[MAX_N][MAX_K * MAX_N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, k;
	cin>>n>>k;
	forn(i, 1, n*k) {
		int a;
		cin>>a;
		c[a]++;
	}
	forn(i, 1, n) {
		int a;
		cin>>a;
		f[a]++;
	}
	forn(i, 1, k) {
		cin>>h[i];
	}
	forn(x, 0, n) {
		forn(y, 0, n*k) {
			forn(i, 0, k)
				dp[x+1][y+i]=max(dp[x+1][y + i], dp[x][y] + h[i]);
		}
	}
	ll ans = 0LL;
	forn(i, 0, MAX_F-1)
		ans+=1LL * dp[f[i]][c[i]];
	cout << ans<<'\n';
	return 0;
}
