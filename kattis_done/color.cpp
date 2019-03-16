/** 
Hard work is worthless for those that don’t believe in themselves.
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
	int s, c;
	long k;
	scanf("%d %d %ld", &s, &c, &k);
	vector<long> cc(s);
	forn(i, 0, s - 1) scanf("%ld", &cc[i]);
	sort(all(cc));
	long ct = 0, cur = - k - 1;
	int curc = 0;
	forn(i, 0, s - 1) {
		if (cc[i] <= cur + k && curc < c) curc++;
		else {
			ct++;
			cur = cc[i];
			curc = 1;
			continue;
		}

	}
	printf("%ld\n", ct);
	return 0;
}
