/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

ll sof(ll p, ll q, ll n) {
	ll t = gcd(p, q);
	p /= t;
	q /= t;
	ll s = 0;
	ll z = 1;
	while(q > 0 && n > 0) {
		t = p/q;
		s += z*t*n * (n + 1) /2;
		p -= q * t;

		t = n/q;
		s += z * p * t * (n + 1) - z * t * (p * q * t + p + q - 1)/2;
		n -= q * t;

		t = (n * p)/ q;
		s += z * t * n;
		n = t;
		swap(p, q);
		z = -z;
	}
	return s;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		ll p, q, n;
		cin>>p>>q>>n;
		ll ans = p * n * (n + 1) / 2;
		
		cout << ans - q *sof(p, q, n) <<'\n';
	}
	return 0;
}
