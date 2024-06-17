/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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
	ll H;
	int n;
	cin>>H>>n;
	vll a(n), b(n);
	ll bestDam = INF;
	forn(i,0,n-1) {
		cin>>a[i];
		if (i > 0) b[i] = b[i-1] + a[i];
		else b[i]=a[i];
		if (b[i] < bestDam) bestDam = b[i];
	}
	if (-bestDam < H  && b[n-1] >= 0) {
		puts("-1");
		return 0;
	}
	ll ans = 0LL;
	if (H <= -bestDam) {
		forn(i,0,n-1) {
			if (-b[i] >= H) {
				ans += i + 1;
				break;
			}
		}
		cout << ans <<'\n';
		return 0;
	}
	ll r =  (ll) ceil(1.0 * (H + bestDam) / -b[n-1]);
	ans += r * n;
	H += b[n-1] * r;

	forn(i,0,n-1) {
		if (-b[i] >= H) {
			ans += i + 1;
			break;
		}
	}
	cout << ans <<'\n';
	
	return 0;
}
