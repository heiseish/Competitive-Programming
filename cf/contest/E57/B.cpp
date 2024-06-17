/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
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
const int MOD = 998244353;
void add(int& a, int b) {
	a+=b;
	if (a >= MOD) a -= MOD;
}

int sum (int a, int b) {
	add(a, b);
	return a;
}

int multiply(int a, int b) {
	return (long long) a * b % MOD;
}

int mpow(int a, int b) {
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

int factorialMOD(int n) {
	int ans = 1;
	forn(i, 2, n) {
		ans = multiply(ans, i);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int cur = 1, head = 1;
	while(s[cur++] == s[0]) head++;
	int tail = 1;
	cur = n - 2;
	while(s[cur--] == s[n - 1]) tail++;
	int ans = 1;
	if (s[0] != s[n - 1]) {
		add(ans, tail);
		add(ans, head);
	} else if (head == n) {
		ans = factorialMOD(n);
	} else {
		add(ans, tail);
		add(ans, head);
		add(ans, multiply(tail, head));
	}
	cout << ans << '\n';
	return 0;
}
