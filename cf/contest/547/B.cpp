/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
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
	int n;
	cin>>n;
	vi a(n);
	forn(i,0,n-1) cin>>a[i];
	vi b = a;
	a.insert(a.end(), all(b));
	a.insert(a.end(), all(b));
	int ans = 0, ct = 0;
	forn(i,0,sz(a)-1) {
		if (a[i] == 1) {
			ct++;
		} else {
			ans=max(ans, ct);
			ct=0;
		}
	}
	if (ct > 0) ans = max(ans, ct);
	cout << ans <<'\n';
	return 0;
}
