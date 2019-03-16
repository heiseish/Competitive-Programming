/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

const int INF = 1 << 30;
/**
Start coding from here
*/
int n, na, nb, ns1, ns2, nset;
ll tot = 0LL;
ll a[20], b[20], set1[70000], set2[70000];
ll minDiff = 0LL, numWay = 0LL;
ll getsum(ll *a, ll id) {
	ll res = 0, i;
	for(i=0;id!=0;++i, id>>=1)
		if(id & 1) res += a[i];
	return res;
}
void solve() {
	ll dif, val, finder, i, j, lowb, uppb;
	ns1 = (1 << na);
	forn(i, 0, ns1-1) set1[i] = getsum(a, i); // Generate all possible sums with bitmasking
	ns2 = (1 << nb);
	forn(i, 0, ns2-1) set2[i] = getsum(b, i); // Generate all possible sums with bitmasking
	sort(set2, set2 + ns2);
	minDiff = -1;
	forn(i, 0, ns1-1) {
		if (minDiff != -1) lowb = (tot - minDiff)/2 - set1[i];
		else lowb = 0;
		uppb = tot/2 + 1 - set1[i];
		lowb = lower_bound(set2, set2 + ns2, lowb) - set2;
		uppb = upper_bound(set2, set2 + ns2, uppb) - set2;
		forn(j, max(lowb - 1, 0LL), uppb-1) {
			val = set1[i] + set2[j];
			dif = abs(tot - val - val);
			if ((dif == minDiff) && (nset == val)) ++numWay;
			else if ((dif < minDiff) || (minDiff == -1)) {
				nset = val;
				minDiff = dif;
				numWay = 1;
			}
		}
	}
	if (minDiff == 0) numWay /=2;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	na=n/2;
	nb=n-na;
	forn(i, 0, na-1) {
		cin>> a[i];
		tot+=a[i];
	}
	forn(i, 0, nb-1) {
		cin>>b[i];
		tot+=b[i];
	}
	solve();
	cout << minDiff << ' ' << numWay << '\n';
	return 0;
}
