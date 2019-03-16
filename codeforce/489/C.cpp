/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (ll)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())

using namespace std;
typedef long long ll;

const ll INF = 1 << 30;
/**
Start coding from here
*/
const int MOD=1e9+7;
void add(ll& a, ll b) {
	a+=b;
	if (a >= MOD) a -= MOD;
}

void subtract(ll& a, ll b) {
	if (b>a) a+=MOD;
	a=(a-b)%MOD;
}

ll sum (ll a, ll b) {
	add(a, b);
	return a;
}

ll multiply(ll a, ll b) {
	return (long long) ((a%MOD) * (b%MOD)) % MOD;
}

ll mpow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) {
			ret = multiply(ret, a);
		}
		a = multiply(a, a);
		b >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll x, k;
	cin>>x>>k;
	if(x==0) {
		cout<<"0\n";
		exit(0);
	}
	ll ans = multiply(x, mpow(2LL, k+1));
	ll temp = mpow(2LL, k);
	subtract(temp, 1LL);
	// debug(temp);
	subtract(ans, temp);
	cout<< ans<<'\n';
	return 0;
}
