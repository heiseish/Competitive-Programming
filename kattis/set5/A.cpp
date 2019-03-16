/** 
it is foolish to fear what we have to see and know”        
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
#define mp make_pair

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
const int maxn = 2000 + 3;
const int maxk = 1e5 + 7;
pi a[maxn];
double EPS = 1e-9;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	scanf("%d", &tc);
	int n;
	while(tc--) {
		vector<unordered_set<int> > f(maxk);
		cin>>n;
		forn(i,0,n-1) {
			scanf("%d %d", &a[i].st, &a[i].nd);
			a[i].st+=50000;
			a[i].nd+=50000;
			f[a[i].st].insert(a[i].nd);
		}
		
		int ans = 0;
		forn(i,0,n-1) forn(j,i+1,n-1) {
			double xmid, ymid;
			xmid = (a[i].st + a[j].st)/2.0;
			ymid = (a[i].nd + a[j].nd)/2.0;
			double tox = a[i].st - xmid, toy = a[i].nd - ymid;
			int newx1 = round(xmid + toy), newy1 = round(ymid - tox);
			if (!(abs(xmid + toy - newx1) < EPS && 
				abs(ymid - tox - newy1) < EPS)) continue;
	
			int newx2 = round(xmid - toy), newy2 = round(ymid + tox);
			if (!(abs(xmid - toy - newx2) < EPS && 
				abs(ymid + tox - newy2) < EPS)) continue;
			
			if (!(sz(f[newx1]) != 0 && f[newx1].count(newy1)))
				 continue;

			if (!(sz(f[newx2]) != 0 && f[newx2].count(newy2)))
				 continue;
			ans++;
				
		}
		printf("%d\n", ans/2);
	}
	return 0;
}
