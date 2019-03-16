/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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
	int n, k;
	scanf("%d %d", &n, &k);
	vi a(n);
	forn(i, 0, n - 1) scanf("%d", &a[i]);
	sort(all(a));
	int cur = 0, sub = 0;
	forn(i, 0, k - 1) {
		if (cur > n - 1) {
			printf("0\n"); 
			continue;
		}
		printf("%d\n", a[cur] - sub);
		while(cur < n - 1 && a[cur] == a[cur + 1]) 
			cur++;
		sub = a[cur];
		cur++;
	}
	return 0;
}
