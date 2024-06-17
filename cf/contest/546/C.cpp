/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
const int maxn = 503;
int A[maxn][maxn], B[maxn][maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	cin>>n>>m;
	forn(i,1,n) forn(j,1,m) cin>>A[i][j];
	forn(i,1,n) forn(j,1,m) cin>>B[i][j];
	int curx = 1, cury = 1;
	bool can = true;
	forn(i,1, n + m - 1) {
		vi a, b;
		int x = curx, y = cury;
		while(x >= 1 && y <= m) {
			a.pb(A[x][y]);
			b.pb(B[x][y]);
			x--;
			y++;
		}
		sort(all(a));
		sort(all(b));
		if (a!=b) {
			can = false;
			break;
		}
		if (curx < n) {
			curx++;
		} else {
			cury++;
		}
	}
	if (can) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
