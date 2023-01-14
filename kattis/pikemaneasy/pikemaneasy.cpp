/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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
const int MOD = 1000000007;
void add(ll& a, ll b) {
	a += b;
	if (a >= MOD) a-=MOD;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, T;
	cin>>n>>T;
	ll a, b, c, t;
	cin>>a>>b>>c>>t;
	vll k;
	forn(i,1,n) {
		k.pb(t);
		t =  (((a * t) + b) % c ) + 1;
	}
	sort(all(k));
	// for(auto &v : k) debug(v);
	ll ans = 0;
	int ct=0;
	ll ti = 0;
	for(auto &v : k) {
		if (ti + v > T) break;
		ti+=v;
		add(ans, ti);
		ct++;
	}
	cout << ct << ' ' << ans <<'\n';
	return 0;
}
