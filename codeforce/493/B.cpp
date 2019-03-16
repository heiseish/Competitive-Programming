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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, b;
	cin>>n>>b;
	vi a(n);
	vi d;
	int o=0, e=0;
	forn(i,0,n-1) {
		cin>>a[i];
	}
	forn(i,0,n-1) {
		if(a[i]%2==0) e++;
		else o++;
		if(e==o && i < n-1) d.pb(abs(a[i] - a[i+1]));
	}
	if(d.empty()) {
		cout<<"0\n";
		return 0;
	}
	sort(all(d));
	int ans = 0, ct=0;
	while(ans + d[ct] <= b && ct < sz(d)) {
		ans+=d[ct++];
	}
	cout << ct<<'\n';
	return 0;
}
