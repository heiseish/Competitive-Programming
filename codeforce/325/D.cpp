/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int) x.size()
#define mp make_pair
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll INF = 5000000000LL;
/**
Start coding from here
*/
const ll maxn = 2e5 + 10;
vector<pair<pi, ll> > v;
ll n, m, k, i, j, a[30][4];
ll x1 = -INF, yy = INF, l1 = -INF, l2 = -INF, s1 = -INF;
vector<string> ans;
ll f(ll t, ll x, ll y, ll l, ll p) {
	if (t == (n + 1)/2 + 1 && !p) {
		v.pb(mp(mp(x, y), l));
		return 0;
	}
	if (t == n + 1) {
		ll k = lower_bound(all(v), mp(mp(-x, -y), INF)) - v.begin() - 1;
		if (k >= 0 && k < sz(v) && mp(-x, -y) == v[k].st) {
			if (v[k].nd + l > s1) {
				x1 = -x; yy = -y; l1 = v[k].nd; l2 = l;
				s1 = l1 + l2;
			}
		}
		return 0;
	}
	f(t + 1, x + a[t][1], y + a[t][2], l + a[t][1] + a[t][2], p);
	f(t + 1, x + a[t][1] - a[t][0], y - a[t][0], l+a[t][1] + a[t][0], p);
	f(t + 1, x - a[t][0], y + a[t][2] - a[t][0], l + a[t][0] + a[t][2], p);
	return 0;
}

ll f2(ll t, ll x, ll y, ll l, ll p) {
	if (t == (n+1)/2 + 1 && !p)
		return (x1 == x && yy == y && l == l1);
	if (t == n + 1)
		return (x1 == -x && yy == -y && l == l2);
	if (f2(t+1, x+a[t][1], y + a[t][2], l + a[t][1] + a[t][2], p)) {
		ans.pb("MW");
		return 1;
	}
	if (f2(t+1, x+a[t][1] - a[t][0], y - a[t][0], l + a[t][1] + a[t][0], p)) {
		ans.pb("LM");
		return 1;
	}
	if (f2(t+1, x-a[t][0], y + a[t][2] - a[t][0], l + a[t][0] + a[t][2], p)) {
		ans.pb("LW");
		return 1;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	forn(i, 1, n) cin>>a[i][0]>>a[i][1]>>a[i][2];
	f(1, 0, 0, 0, 0);
	sort(all(v));
	f((n+1)/2+1, 0, 0, 0, 1);
	f2((n+1)/2+1, 0, 0, 0, 1);
	f2(1, 0, 0, 0, 0);
	if (ans.empty()) {
		puts("Impossible");
		return 0;
	}
	reverse(all(ans));
	forn(i, 0, sz(ans) - 1) cout << ans[i]<<'\n';
	return 0;
}
