/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
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
int eval(vector<int> d) {
	int s = 0;
	forn(i, 0, d.size() - 1) {
		s+= (d[i] * pow(10, d.size() - 1 - i));
	}
	return s;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int a = n;
	vector<int> d;
	while (a > 0) {
		int b = a % 10;
		d.pb(b);
		a/=10;
	}
	int MAX = 1e6;
	sort(d.begin(), d.end());
	do {
		int e = eval(d);
		if (e > n && e < MAX) MAX = e;
	} while(next_permutation(d.begin(), d.end()));
	if (MAX == 1e6) printf("0\n");
	else printf("%d\n", MAX);
	return 0;
}
