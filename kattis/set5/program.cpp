/** 
Those who cannot acknowledge themselves will eventually fail.        
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
const int maxn=1e6 + 3;
int a[maxn], ta[maxn];
const int maxs = 1003;
int bucket[maxs][maxs];
ll ans[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, k;
    cin>>n>>k;
    int t;
	forn(i,1,k) {
		cin>>t;
		ta[t]++;
	}
	int ss=sqrt(n) + 1;
    forn(i,1,n){
		if (!ta[i]) continue;
        if(i <= ss-1) bucket[i][0]++;
        else {
            int j=0;
            while(j <= n) {
                a[j]+=ta[i];
                j+=i;
            }
        }
    }
	forn(i, 0, n-1) {
        int d=a[i];
        forn(j,1,ss-1) d+=bucket[j][i%j];
        if(i>0) ans[i]=ans[i-1]+d;
        else ans[i]=d;
    }
	int q;
	cin>>q;
	forn(i,1,q) {
		int l, r;
		cin>>l>>r;
		r++;
		cout<<ans[r]-ans[l]<<'\n';
	}
	return 0;
}
