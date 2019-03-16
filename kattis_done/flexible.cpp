/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.
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
const int maxn = 101;
int hl[maxn];
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, p;
	scanf("%d %d", &n, &p);
	vector<int> pa(p + 2);
	pa[0] = 0;
	pa[p + 1] = n;
	forn(i, 1, p) scanf("%d", &pa[i]);
	forn(i, 0, p + 1) {
		forn(j, i + 1, p + 1) {
			hl[pa[j] - pa[i]] = true;
		}
	}
	forn(i, 0, n + 1) 
		if (hl[i])
			printf("%d ", i);

	printf("\n");

	return 0;
}
