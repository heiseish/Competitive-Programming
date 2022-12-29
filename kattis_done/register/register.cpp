/** 
I’m the only one who can bear the full brunt of your hate! It’s my job, no one else’s! I’ll bear the burden of your hatred… and we’ll die together!
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

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> p {2, 3, 5, 7, 11, 13, 17, 19};
	vector<int> r(8);
	forn(i, 0, 7) scanf("%d", &r[i]);
	ll res = 0;
	forn(i, 0, 7) {
		int temp = 1;
		forn(j, 0, i - 1) {
			temp*=p[j];
		}
		temp*=(p[i] - r[i] - 1);
		res+=temp;
	}
	printf("%lld\n", res);
	return 0;
}
