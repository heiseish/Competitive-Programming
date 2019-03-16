/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
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
const int maxn = 2e5 + 5;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll n, k;
	cin>>n>>k;
	vector<vector<pll> > b(k);
	vpll a(n);
	forn(i,0,n-1) cin>>a[i].st;
	forn(i,0,n-1) cin>>a[i].nd;
	for (auto &p : a) {
		ll idx = (ll) round(p.st / p.nd);
		if (idx < k-1) b[idx].pb({p.st - idx * p.nd, p.nd});
	}
	ll lo = -1, hi = 2e12;
	while(lo + 1 < hi) {
		ll mid = (lo + hi) >> 1;
		int kidx = 0;
		vector<vpll> c = b;
		while(c[kidx].empty() && kidx < k) ++kidx;
		
		bool can = true;
		forn(i,0,k-1) {
			while(c[kidx].empty() && kidx < k) ++kidx;
			if (kidx == k) break;
			if (i == kidx && sz(c[kidx]) > 1) {
				if (mid == 5) {
					debug(i);
					debug(kidx);
				}
				can = false;
				break;
			}
			if (i > kidx) {
				can = false;
				break;
			}
			pll cur = c[kidx].back(); c[kidx].pop_back();
			cur.st += mid;
			if (cur.st < 0) {
				can = false;
				break;
			}
			ll idx = (ll) round(cur.st / cur.nd);
			if (kidx + idx < k-1) c[kidx + idx].pb({cur.st - idx * cur.nd, cur.nd});
		}
		if (can) hi = mid;
		else lo = mid;
	}
	if (hi == 2e12) puts("-1");
	else cout << hi << '\n';
	return 0;
}
