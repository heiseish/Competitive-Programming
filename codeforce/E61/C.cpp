/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
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
const int maxn = 5005;
pi p[maxn];
int c[maxn], d[maxn], e[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, q;
	cin>>n>>q;
	forn(i,1,q) {
		cin>>p[i].st>>p[i].nd;
		forn(j,p[i].st, p[i].nd) c[j]++;
	}
	int ans = 0;
	forn(i,1,q) {
		int ct = 0;
		forn(j,p[i].st, p[i].nd) c[j]--;
		forn(j,1,n) if (c[j] > 0) ct++;
		forn(j,1,n) d[j] = (c[j]  == 1);
		forn(j,1,n) e[j] = e[j-1] + d[j];
		forn(j,1,q) {
			if (j == i) continue;
			ans = max(ans, ct - (e[p[j].nd] - e[p[j].st - 1]));
		}
		forn(j,p[i].st, p[i].nd) c[j]++;
	}
	cout << ans <<'\n';
	return 0;
}
