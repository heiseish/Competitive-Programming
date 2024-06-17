/** 
Those who do not understand true pain can never understand true peace.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, k;
	cin>>n>>k;
	vi a(n);
	unordered_map<int, int> d;
	forn(i,0,n-1) {
		cin>>a[i];
		d[a[i]%k]++;
	}
	int m = k % 2 == 0 ? k/2 - 1: k /2;
	int ans = d[0]/2;
	forn(i,1,m) {
		ans += min(d[i], d[k-i]);
	}
	if (k % 2 == 0) ans += d[k/2]/2;
	cout << ans   *2<<'\n';

	return 0;
}
