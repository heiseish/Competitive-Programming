/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.
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
	int n;
	scanf("%d", &n);
	vi it(n);
	forn(i, 0, n - 1) scanf("%d", &it[i]);
	sort(all(it), greater<int>());
	ll ct = 0;
	for (int i = 2 ; i <= n -1; i+=3){
		ct+=it[i];
	}
	printf("%lld\n", ct);
	return 0;
}
