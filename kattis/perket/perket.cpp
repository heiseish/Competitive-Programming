/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?
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
const int maxn = 10;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	long sour[maxn];
	long bitter[maxn];
	forn(i, 0, n - 1) scanf("%ld %ld", &sour[i], &bitter[i]);
	
	long MIN = inf;
	forn(i, 1, pow(2, n) - 1) {
		bitset< 10 > b(i);
		// cout << b.to_string() << endl;
		long m = 1, s = 0;
		forn(i, 0, n - 1) {
			if (b[i]) {
				m*=sour[i];
				s+=bitter[i];
			}
		}
		if (abs(m - s) < MIN) MIN = abs( m - s);
	} 
	printf("%ld\n", MIN);

	return 0;
}
