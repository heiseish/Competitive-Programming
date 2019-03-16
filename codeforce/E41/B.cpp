/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
	int n, k;
	cin>>n>>k;
	vi a(n), t(n), b(n, 0);
	forn(i,0,n-1) cin>>a[i];
	forn(i,0,n-1) {
		cin>>t[i];
		if(t[i]==0) b[i]=a[i];
	}
	int curans = accumulate(all(a), 0) - accumulate(all(b), 0);
	int ans = accumulate(b.begin(), b.begin() + k, 0);
	int cur = ans;
	forn(i, 1, n-k) {
		cur = cur - b[i-1] + b[i+ k-1];
		ans = max(ans, cur);
	}
	cout << curans + ans<<'\n';
	return 0;
}
