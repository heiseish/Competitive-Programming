/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi a(n), b(n), c(n-1), d(n-1);
	forn(i, 0, n-1) {
		cin>>a[i];
		if (i > 0) c[i-1] = a[i] - a[i-1]; 
	}
	forn(i, 0, n-1) {
		cin>>b[i];
		if (i > 0) d[i-1] = b[i] - b[i-1]; 
	}
	if (a[0] != b[0] || a[n-1] != b[n-1]) {
		cout << "No\n";
		return 0;
	}
	sort(all(c));
	sort(all(d));
	forn(i, 0,  n - 2) {
		if (c[i] != d[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}
