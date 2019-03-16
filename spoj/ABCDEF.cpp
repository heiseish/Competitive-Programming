/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
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
	vi a(n);
	forn(i, 0, n-1) cin>>a[i];
	unordered_map<int, int> g;
	g.reserve(1000000);
	forn(i, 0, n-1) forn(j, 0, n-1) forn(k, 0, n-1)
		g[a[i] * a[j] + a[k]]++;
	ll ans = 0LL;
	forn(i, 0, n-1) forn(j, 0, n-1) forn(k, 0, n-1) {
		if (a[k] == 0) continue;
		if (g.count((a[i] + a[j]) * a[k]))
			ans += g[(a[i] + a[j]) * a[k]];
	}
	cout << ans<<'\n';

	return 0;
}
