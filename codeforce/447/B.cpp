/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
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
const int MOD = 1e9+7;
int multiply(ll a, ll b) {
	return (long long) ((a%MOD) * (b%MOD)) % MOD;
}

int mpow(ll a, ll b) {
	int ret = 1;
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
	ll n, m;
	int k;
	cin>>n>>m>>k;
	if (k == -1 && n%2 != m%2) cout << 0 <<'\n';
	else cout << mpow(mpow(2, (n -1)),  (m -1)) <<'\n';
	return 0;
}
