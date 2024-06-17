/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi ans;
	forn(i, 1, n) {
		if (n%i==0) ans.pb(i);
	}
	ll res =  1L * INF;
	for (auto &v : ans){
		ll f =  1L * k * v + n/v;
		ll s = 1L * k * n / v + v;
		if (f%k != 0 && (f/k) * (f%k) == n) res = min<ll>(res,  f);
		if (s%k != 0 && (s/k) * (s%k) == n) res = min<ll>(res,  s);
	}
	cout << res << '\n';
	return 0;
}
