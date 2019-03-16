/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.        
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
	int n;
	cin >> n;
	vi t;
	if (n <= 100) {
		forn(i, 1, n/2) if (n%i==0) t.pb(i);
	} else {
		forn(i, 1, n/100) if (n%i==0) t.pb(i);
		for(int j = 99; j >= 2;j--) {
			if (n%(n/j) == 0) t.pb(n/j);
		}
	}
	t.pb(n);
	vll ans;
	for (auto &v : t) {
		int last = n + 1 - v;
		int num = (last - 1)/ v + 1;
		double mid = (1.0 + last) /2;
		ll next = 1ll * num * mid;
		ans.pb(next);
	}
	ll cur = 0;
	for (int i = (int) ans.size() - 1; i >= 0; i--) {
		ll v = ans[i];
		if (v!=cur) {
			cout << v << ' ';
			cur = v;
		}
	}
	cout << '\n';
	return 0;
}
