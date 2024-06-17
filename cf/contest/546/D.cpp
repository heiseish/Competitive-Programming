/** 
you can do it too because you are not a failure like me.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	cin>>n>>m;
	vi b(n + 1);
	forn(i,1,n) cin>>b[i];
	vector<unordered_set<int> > a(n + 1);
	forn(i,1,m) {
		int x, y;
		cin>>x>>y;
		a[x].insert(y);
	}
	vi P;
	P.pb(b.back());
	int ans = 0;
	for(int i = n - 1; i >= 1; --i) {
		bool can = true;
		for (auto &v : P) {
			if (!a[b[i]].count(v)) {
				can = false;
				break;
			}
		}
		if (!can) P.pb(b[i]);
		else ans++;
	}
	cout << ans <<'\n';
	return 0;
}
