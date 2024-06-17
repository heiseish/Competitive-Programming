/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (ll)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;
#define LSOne(S) ((S) & -(S))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef vector<pair<ll, ll> > vpi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll INF = 1 << 30;
/**
Start coding from here
*/

class RURQ {
private: 
	vll fta, ftb; ll n;  
public:
	RURQ(ll _n) : n(_n) {
		fta.assign(n+1, 0);
		ftb.assign(n+1, 0);
	}
	ll queryA(ll b)	{
		ll sum = 0LL;
		for (; b; b -= LSOne(b)) sum += fta[b];
		return sum;
	}

	ll queryB(ll b)	{
		ll sum = 0LL;
		for (; b; b -= LSOne(b)) sum += ftb[b];
		return sum;
	}

	ll query(ll b) {
		return queryA(b) * b - queryB(b);
	}

	ll query(ll i, ll j) {
		return query(j) - query(i - 1);
	}

	// Poll update: Adds v to the value at position k in the array
	// ft is the fenwick tree which represents that array
	void updateA(ll k, ll v) {
		for (; k <= n; k += LSOne(k)) fta[k] += v;
	}

	void updateB(ll k, ll v) {
		for (; k <= n; k += LSOne(k)) ftb[k] += v;
	}

	// Range update: Adds v to each element in [i...j]
	void range_update(ll i, ll j, ll v)	{
		updateA(i, v);
		updateA(j + 1, -v);
		updateB(i, v * (i - 1));
		updateB(j + 1, -v * j);
	}

};


bool cmp(pll& lhs, pll& rhs) {
	return lhs.st < rhs.st;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll n;
	cin>>n;
	vll a(n+1), f(n+1, 0);
	forn(i,1,n) {
		cin>>a[i];
		f[i]=f[i-1] +a[i];
	}
	unordered_map<ll, vpll> g;
	forn(i,1,n) forn(j,i,n) {
		g[f[j]-f[i-1]].pb({i, j});
	}
	ll best = 0;
	vpi ans;
	for (auto &v : g) {
		vpll temp;
		sort(all(v.nd), cmp);
		// RURQ check(n);
		for (auto &p : v.nd) {
			// if (check.query(p.st, p.nd) == 0)  {
			// 	temp.pb(p);
			// 	check.range_update(p.st, p.nd, 1);
			// }
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
