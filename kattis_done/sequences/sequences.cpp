/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?        
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
typedef unsigned long long ll;
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
const int MOD = 1e9 + 7;
void add(ll& a, ll b) {
	a += b;
	a %= MOD;
}
ll multiply(ll a, ll b) {
	return ((a%MOD) * (b%MOD)) % MOD;
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
const int maxn = 5e5 + 5;
int q[maxn], o[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	int l = sz(s);
	ll numZero = 0, numQ = 0;
	ll ans = 0;
	int cq=0, co = 0;
	forn(i,0,l-1) {
		q[i]=cq;
		o[i]=co;
		if (s[i] == '?') cq++;
		if (s[i] == '1') co++;
	}
	for(int i = l-1; i>=0; i--) {
		if (s[i] == '?') {
			ll toadd = 0LL;
			add(toadd, multiply(numZero, mpow(2, numQ)));
			if (numQ) add(toadd, multiply(numQ, mpow(2, numQ-1)));
			toadd = multiply(toadd, mpow(2, q[i]));
			add(ans, toadd);
			numQ++;
		} else if (s[i] == '1') {
			ll toadd = 0LL;
			add(toadd, multiply(numZero, mpow(2, numQ)));
			if (numQ) add(toadd, multiply(numQ, mpow(2, numQ-1)));
			toadd = multiply(toadd, mpow(2, q[i]));
			add(ans, toadd);
		} else {
			numZero++;
		}
	}
	cout << ans<<'\n';
	return 0;
}
