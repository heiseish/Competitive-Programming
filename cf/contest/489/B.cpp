/** 
It does not do to dwell on dreams and forget to live.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(ll i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (ll)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll INF = 1 << 30;
/**
Start coding from here
*/
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll l, r, x, y;
	cin>>l>>r>>x>>y;
	ll tot= x * y;
	vll ans;
	ll t = sqrt(y);
	for(ll i=1L; i<=min(t, r);i++) {
		if(y%i==0) {
			ans.pb(i);
			if (i!=y/i) ans.pb(y/i);
		}
	}
	sort(all(ans));
	UNIQUE(ans);
	ll ct=0;
	for(auto &v : ans) {
		// debug(v);
		if (v<l||v>r) continue;
		if (tot%v!=0) continue;
		if (tot/v<l||tot/v>r) continue;
		if (gcd(v, tot/v) == x && lcm(v, tot/v)==y) {
			// debug(v);
			// if (v==tot/v) dc++;
			ct++;
		}
	}
	cout<<ct<<'\n';
	return 0;
}
