/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
	unordered_map<int, int> d, g;
	forn(i,0,n-1) {
		cin>>a[i];
		g[a[i]]++;
	}
	forn(i,0,n-1) forn(j,i+1,n-1) {
		d[a[i]+a[j]]++;
	}
	int ans=-INF;
	forn(i, 0,n-1) forn(j,0,n-1) {
		if (i==j) continue;
		int h=a[i]-a[j];
		if (d.count(h)) {
			int toOff = g.count(-a[j]);
			toOff += g.count(a[i] - 2 * a[j]);
			if ((a[i]-a[j])%2==0) toOff+=g.count((a[i]-a[j])/2);
			if (d[h] - toOff > 0) ans=max(ans, a[i]);
		}
		
	}
	if(ans==-INF)cout<<"no solution\n";
	else cout<<ans<<'\n';
	return 0;
}
