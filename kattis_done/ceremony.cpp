/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first

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

const int inf = 1 << 30;
/**
Start coding from here
*/

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	vector<ll> t(n);
	map<ll, ll> h;
	forn(i, 0, n - 1) {
		scanf("%lld", &t[i]);
		h[t[i]]++;
	}
	ll f = 0, c = 0;
	ll s = 0;
	for(auto i : h) {
		s += i.nd;
		if (i.st - f <= s - c) {
			f = i.st;	
			c = s;
		}
	}
	// cout << f << " " << n << " " << c << " \n";
	if (c == 0) printf("%d\n", n);
	else printf("%lld\n", f + n - c);

	return 0;
}
