/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.
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
	int MAX = 0, MAXidx = 0;
	forn(i, 1, 5) {
		int s = 0;
		forn(j, 1, 4) {
			int temp;
			scanf("%d", &temp);
			s+=temp;
		}
		if (s > MAX) {
			MAX = s;
			MAXidx = i;
		}
	}
	printf("%d %d\n", MAXidx, MAX);
	return 0;
}
