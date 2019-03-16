/** 
Those who cannot acknowledge themselves will eventually fail.
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
	int n, p;
	scanf("%d %d", &n, &p);
	vi ee(n);
	forn(i, 0, n-1) {
		scanf("%d", &ee[i]);
		ee[i]-=p;
	}
	ll sum = 0L, MAX = 0L;
	forn(i, 0, n-1){
		sum+=ee[i];
		MAX=max(sum, MAX);
		if (sum < 0) sum = 0L;
	}
	printf("%lld\n", MAX);
	return 0;
}
