/** 
Hard work is worthless for those that don’t believe in themselves.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 1e5 + 3;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, b;
	cin>>n>>b;
	vi a(n);
	vi g(n,0);
	int idx =-1;
	forn(i, 0, n-1){
		cin>>a[i];
		g[i]=a[i]>b?1:a[i]<b?-1:0;
		if (a[i]==b) idx=i;
	}
	unordered_map<int, int> track;
	ll ans = 0LL;
	int cur=0;
	for(int i=idx;i>=0;i--) {
		cur+=g[i];
		track[cur]++;
	}
	cur=0;
	forn(i, idx, n-1) {
		cur+=g[i];
		ans+=track[-cur];
	}
	cout<< ans<<'\n';

	return 0;
}
