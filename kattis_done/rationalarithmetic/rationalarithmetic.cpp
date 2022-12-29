/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	while(N--) {
		ll x1, y1, x2, y2;
		char op;
		cin >> x1 >> y1 >> op >> x2 >> y2;
		if (op == '+') {
			ll denom = lcm(y1, y2);
			ll num1 = x1 * (denom/ y1);
			ll num2 = x2 * (denom/ y2);
			ll g = (!x1 || !x2) ? 1 : gcd(abs(num1 + num2), abs(denom));
			ll denum = (num1 + num2) / g;
			denom /= g;
			cout << denum << " / " << denom << '\n';
		} else if (op == '-') {
			ll denom = lcm(y1, y2);
			ll num1 = x1 * (denom/ y1);
			ll num2 = x2 * (denom/ y2);
			ll res = num1 - num2;
			ll g = (!x1 || !x2) ? 1 : gcd(abs(res), abs(denom));
			ll denum = res/g;
			denom /= g;
			cout << denum << " / " << denom << '\n';
		} else if (op == '*') {
			ll num = x1 * x2;
			ll denum = y1 * y2;
			ll g = (!x1 || !x2) ? 1 : gcd(abs(num), abs(denum));
			num/=g; denum/=g;
			cout << num << " / " << denum << '\n';
		} else {
			ll num = x1 * y2;
			ll denum = y1 * x2;
			ll g = (!x1 || !x2) ? 1 : gcd(abs(num), abs(denum));
			num/=g; denum/=g;
			cout << num << " / " << denum << '\n';
		}
	}
	return 0;
}
