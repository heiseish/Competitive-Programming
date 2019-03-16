/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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
	int n;
	cin>>n;
	vi a(2 * n);
	vector<vi> b(n);
	forn(i,0,2*n-1) {
		cin>>a[i];
		b[a[i]-1].pb(i);
	}
	ll ans = 0;
	int cur1 = 0, cur2 = 0;
	forn(i,0,n-1) {
		int f = b[i][0], s = b[i][1];
		ans += min(abs(cur1 - f) + abs(cur2 - s), abs(cur1 - s) +  abs(cur2 - f));
		cur1=f;
		cur2=s;
	}
	cout << ans <<'\n';
	return 0;
}
