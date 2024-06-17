/** 
it is foolish to fear what we have to see and know”        
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
	int n, m;
	cin>>n>>m;
	vector<vi> a(n);
	forn(i,0,m-1){
		int x, y;
		cin>>x>>y;
		x--;y--;
		a[x].pb(y);
	}
	forn(i,0,n-1) {
		int st = i;
		int ans = 0;
		forn(j,0,n-1)  {
			int k = a[j].empty() ? 0 : INF;
			for (auto &v : a[j]) {
				int dist;
				if (v < j) dist = v + n - j;
				else if (v > j) dist = v - j;
				else dist = 0;
				k = min(k, dist);
			}
			int d;
			if (i == j) d = 0;
			else if (i > j) d = j + n - i;
			else d = j - i;
			d += n * (sz(a[j])-1);
			if (!a[j].empty()) k += d;
			ans = max(ans, k);
		}
		cout << ans << ' ';
	}
	cout <<'\n';
	return 0;
}
