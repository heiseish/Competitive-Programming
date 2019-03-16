/** 
Justice isn’t something that you can just proclaim. It’s a feeling you should keep near your heart.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

using namespace std;
typedef long long ll;

const ll INF = 1 << 30;
/**
Start coding from here
*/
const ll MOD = 998244353;
ll N, C, K;



ll multiply(ll a, ll b) {
	return (long long) a * b % MOD;
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

ll modular_inverse(ll n){
	return mpow(n, MOD-2);
}

ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

	ll result = 1;
    forn(i, 1, k) {
        result = multiply(result, n-(k-i));
        result = multiply(result, modular_inverse(i));
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> C >> K;
	ll ans = multiply(C, multiply(nChoosek(N - 1, K), mpow(C - 1, K)));
	cout <<  ans << '\n';
	// cout << backtrack(1, k) << '\n';
	return 0;
}
