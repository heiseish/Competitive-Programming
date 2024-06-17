/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
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
int a[maxn];
int n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	forn(i,0,n-1) cin>>a[i];
	sort(a, a+n);
	int prev = 0, ans = 0;
	forn(i,1,n-1) {
		if (a[i] <= a[prev] + 5) {
			continue;
		} else {
			ans = max(ans, i - prev);
			while(a[prev] + 5 < a[i]) prev++;
		}
	}
	if (prev < n) ans = max(ans, n-prev);
	cout << ans <<'\n';
	return 0;
}
