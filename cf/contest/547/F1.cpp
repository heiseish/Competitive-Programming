/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

bool cmp(pi& lhs, pi& rhs) {
	return lhs.st < rhs.st;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi a(n+1), f(n+1, 0);
	forn(i,1,n) {
		cin>>a[i];
		f[i]=f[i-1] +a[i];
	}
	unordered_map<int, vpi> g;
	forn(i,1,n) forn(j,i,n) {
		g[f[j]-f[i-1]].pb({i, j});
	}
	int best = 0;
	vpi ans;
	for (auto &v : g) {
		vpi temp;
		int curlast = 0;
		sort(all(v.nd), cmp);
		for (auto &p : v.nd) {
			if (temp.empty()) temp.pb(p);
			else {
				if (p.st > temp.back().nd) temp.pb(p);
				else if (p.nd < temp.back().nd) {
					temp.pop_back();
					temp.pb(p);
				}
			}
		}
		if (sz(temp) > best) {
			best = sz(temp);
			ans = temp;
		}
	}
	cout << best <<'\n';
	for (auto &p : ans) cout << p.st << ' ' << p.nd <<'\n';
	return 0;
}
