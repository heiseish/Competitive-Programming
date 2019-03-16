/** 
Those who cannot acknowledge themselves will eventually fail.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vector<ll> > vvi;
typedef pair<ll, ll> pllll;

const ll inf = 1 << 30;
/**
Start coding from here
*/

void findIntersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, ll* xf, ll* yf, ll* xs, ll* ys) {
	*xf = max(x1, x3);
	*yf = max(y1, y3);
	*xs = min(x2, x4);
	*ys = min(y2, y4);
}
bool W(ll x, ll y) {
	return (x + y)%2 == 0;
}
pair<ll, ll> get(ll x1, ll y1, ll x2, ll y2) {
	ll ss = ((abs(x1 - x2) + 1L) * (abs(y1 - y2) + 1L));
	ll n = ss/2;
	if (W(x1, y1) && W(x2, y2) && ss%2!=0) {
		pllll res{n + 1, n};
		return res;
	} else if (!W(x1, y1) && !W(x2, y2) && ss%2!=0) {
		pllll res{n, n + 1};
		return res; 
	} else {
		pllll res{n, n};
		return res;
	} 
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	scanf("%lld", &t);
	while(t--) {
		ll n, m;
		scanf("%lld %lld", &n, &m);
		ll x1, y1, x2, y2;
		ll x3, y3, x4, y4;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
		ll xf, yf, xs, ys;
		findIntersect(x1, y1, x2, y2, x3, y3, x4, y4, &xf, &yf, &xs, &ys);
		pair<ll, ll> total = get(1, 1, m, n);

		pair<ll, ll> stS = get(x1, y1, x2, y2);
		total.st += stS.nd;
		total.nd -= stS.nd;


		if (!(x1 > x4 || x3 > x2 || y1 > y4 || y3 > y2)) {
			pair<ll, ll> dup = get(xf, yf, xs, ys);
			total.st -= dup.nd;
			total.nd += dup.nd;
		}
	
		pair<ll, ll> ndS = get(x3, y3, x4, y4);
		total.st -= ndS.st;
		total.nd += ndS.st;
		printf("%lld %lld\n", total.st, total.nd);
	}
	return 0;
}
