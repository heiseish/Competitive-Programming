/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
long long MOD;
void add(ll& a, ll b) {
	a+=b;
	if (a >= MOD) a -= MOD;
}

ll sum (ll a, ll b) {
	add(a, b);
	return a;
}

ll multiply(int a, ll b) {
	return (long long) a * b % MOD;
}


long long extendedEuclid(long long a, long long b, long long &x, long long& y) {
	long long xx = y=  0;
	long long yy = x = 1;
	while(b) {
		long long q = a/b;
		long long t = b; b = a % b; a = t;
		t =xx; xx = x-q*xx;x=t;
		t = yy; yy= q * yy;y=t;
	}
	return a;
}

long long modInverse(long long b, long long m) {
	long long x, y;
	long long d = extendedEuclid(b, m, x, y);
	if (d!=1) return -1;
	return x%m;
}
long long chineseRemainderTheorem(long long a, long long p, long long b, long long q) {
	long long p1 = modInverse(p, q);
	long long q1 = modInverse(q, p);
	MOD = p * q;
	long long ans = sum(multiply(multiply(a,q),q1), multiply(multiply(b, p),p1));
	// long long ans = (a * q * q1 + b * p * p1) % (p * q);
	if (ans < 0) ans += (p * q);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		ll a, n, b, m;
		cin>>a>>n>>b>>m;
		cout << chineseRemainderTheorem(a, n, b, m) << ' ' << MOD <<'\n';
	}
	return 0;
}
