/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
int getBits(int n) {
	int res = 0;
	while(n > 0) {
		n>>=1;
		res++;
	}
	return res;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int getLargestDiv(int n) {
	int res = 1;
	forn(i, 2, sqrt(n)) {
		if (n%i==0) {
			res = max(res, i);
			res = max(res, n/i);
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int q;
	cin>>q;
	while(q--) {
		int n;
		cin>>n;
		int m = getBits(n);
		if (n == pow(2, m) - 1) cout << getLargestDiv(n) << '\n';
		else cout << (int) pow(2, m) - 1 << '\n';
		// int ans = pow(2, m);
		// cout << ans - 1 <<'\n';
	}
	return 0;
}
