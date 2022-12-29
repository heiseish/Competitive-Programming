/** 
When a man learns to love, he must bear the risk of hatred.
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
	int k;
	scanf("%d", &k);
	vector<int> h(12);
	while(k--) {
		int t;
		scanf("%d", &t);
		forn(i, 0, 11) scanf("%d", &h[i]);
		int ct = 0;
		forn(i, 1, 10) {
			forn(j, 1, 11 - i) {
				int temp = *min_element(h.begin() + j, h.begin() + j + i);
				if (temp > h[j - 1] && temp > h[j + i]) ct++;
			}
		}
		printf("%d %d\n", t, ct);
	}
	return 0;
}
