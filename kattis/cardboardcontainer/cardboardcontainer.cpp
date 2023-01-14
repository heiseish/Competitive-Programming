/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
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
	// #ifdef LOCAL_PROJECT
	// 	freopen("input.txt","r",stdin);
	// #endif
	ll n;
	cin>>n;
	vll d;
	for(ll i =1LL; i <= (ll) n; i++) {
		if ((n * n)%i==0) {
			d.pb(i);
			d.pb((n * n)/i);
		}
	}
	sort(all(d));
	UNIQUE(d);
	ll ans = 1LL << 60;
	for (auto &v : d) {
		forn(i,1,sqrt(v)) {
			if (v%i == 0) {
				ans = min(ans, 2LL * (i + v/i + n * n / v));
			}
		}
		
	}
	cout << ans <<'\n';
	return 0;
}
