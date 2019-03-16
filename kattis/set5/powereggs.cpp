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
const int maxk=35;
ll dp[maxk][maxk];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
	forn(i, 1, 32) forn(j, 0, 32) {
		if (i==1) dp[i][j]=j;
		else if(j==0) dp[i][j]=0;
		else dp[i][j]=dp[i-1][j-1]+1+dp[i][j-1];
	}
	forn(i, 1, 32) {
		forn(j, 0, 32) {
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}
    int tc;
    cin>>tc;
    while(tc--) {
        int n, k;
        cin>>n>>k;
        auto ans=lower_bound(dp[k]+1, dp[k]+33, n) - dp[k];
		if(ans>32) cout << "Impossible\n";
		else cout << ans <<'\n';
        
    }
    return 0;
}