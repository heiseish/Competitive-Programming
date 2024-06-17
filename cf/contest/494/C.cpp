/** 
it is foolish to fear what we have to see and know”        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, k;
	cin>>n>>k;
	vi a(n+1,0), b(n+1,0);
	forn(i,1,n){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	double ans=0.0;
	forn(i,k,n) {
		forn(j,1,n-i+1) {
			ans=max(ans, (double) (b[j+i-1]-b[j-1]) / (1.0 * i));
		}
	}
	cout<<setprecision(20)<<ans<<'\n';
	return 0;
}
