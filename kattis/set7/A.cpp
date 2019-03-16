/**
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
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
const int maxn = 21;
int g[maxn][maxn];
int n;
int dp[1 << 19][20];
int DONE;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	forn (tc,1,5){
        cin>>n;
        DONE = (1 << (n-1)) - 1;
        forn(i,0,n-1) forn(j,0,n-1) cin>>g[i][j];
		forn(i,0,DONE) forn(j,0,n-2) 
			dp[i][j] = INF;

        forn(i,0,n-2) 
			dp[1 << i][i] = g[0][i + 1];

		forn(i,1,DONE) {
			forn(j,0,n-2) {
				if(!(i & (1 << j))) continue;
				int left = DONE - i;
				while(left) {
					int pos = left & -left;
					int p = log2(pos);
					dp[i | pos][p] = min(dp[i | pos][p], g[j + 1][p + 1] + dp[i][j]);
					left-=pos;
				}
			}
		}
		int ans = INF;
		forn(i,0,n-2) {
			ans = min(ans, dp[DONE][i] + g[i+1][0]);
		}
		cout << ans <<'\n';
		
	}
	return 0;
}