/** 
Those who cannot acknowledge themselves will eventually fail.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
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
ll n;
bool can(ll x) {
	ll t=n;
	ll ans = 0LL;
	ll e;
	ll thres=n%2==0?n/2:n/2+1;
	ll ce;
	while(t>0) {
		ce=min(x,t);
		t-=ce;
		ans+=ce;
		e=t/10;
		t-=e;
		if(ans >= thres) return true;
	}
	if(ans>=thres) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	ll lo = 0, hi = n;
	while(lo+1<hi) {
		ll mid=(lo+hi)>>1;
		if(can(mid)) hi=mid;
		else lo = mid;
	}
	cout<<hi<<'\n';
	return 0;
}
