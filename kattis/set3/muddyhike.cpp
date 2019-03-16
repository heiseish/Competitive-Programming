/** 
        
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
typedef pair<int, pi> pipi;
const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 1e3 + 3;
const int dir[] = {0, -1, 1, 0, 0, 1, -1, 0};
int board[maxn][maxn], vis[maxn][maxn];
int r, c;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>r>>c;
	forn(i,0,r-1) forn(j,0,c-1)
		cin>>board[i][j];
	int ans=0;
	priority_queue<pipi, vector<pipi>, greater<pipi> > q;
	forn(i, 0, r-1) q.push({board[i][0], {i, 0}});
	while (true) {
		pipi t = q.top();q.pop();
		vis[t.nd.st][t.nd.nd]++;
		ans=max(t.st, ans);
		if (t.nd.nd == c-1) break;
		forn(k, 0, 3) {
			int ii = t.nd.st + dir[k * 2];
			int jj = t.nd.nd + dir[k * 2 + 1];
			if (ii < 0 || ii >= r) continue;
			if (jj < 0 || jj >= c) continue;
			if (vis[ii][jj]) continue;
			q.push({board[ii][jj], {ii, jj}});
		}
	}
	cout<<ans<<'\n';
	return 0;
}
