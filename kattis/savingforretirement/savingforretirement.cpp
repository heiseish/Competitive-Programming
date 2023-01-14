/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
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
	int b, br, bs, a, as;
	scanf("%d %d %d %d %d", &b, &br, &bs, &a, &as);
	int g = (br - b) * bs;
	int ar = a;
	while ((ar - a) * as <= g) ar++;
	printf("%d\n", ar);
	return 0;
}
