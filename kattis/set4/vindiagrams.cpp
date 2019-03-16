/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
const int maxn = 1e2 + 3;
int vis[maxn][maxn];
int r, c;
vector<string> board;
pi A, B;
vpi inter;
int numBoard=0, outer= 0;
int dfs(int i, int j, int cover=0) {
	vis[i][j]++;
	int ans = 1;
	if (cover) board[i][j] = 'X';
	forn(k, i-1, i+1) forn(l, j-1, j+1) {
		if (k < 0 || k >= r || l < 0 || l >= c || vis[k][l] || board[k][l] != '.') continue;
		ans += dfs(k, l, cover);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>r>>c;
	board.resize(r);
	forn(i, 0, r-1) cin>>board[i];
	forn(i, 0, r-1) forn(j, 0, c-1) {
		if (board[i][j] == 'A') A = make_pair(i, j);
		if (board[i][j] == 'B') B = make_pair(i, j);
		if (board[i][j] != '.') numBoard++;
		if (i > 0 && j > 0 && i < r-1 && j < c-1 && 
			board[i][j] == 'X' && board[i-1][j] == 'X' && board[i+1][j] == 'X'
			&& board[i][j-1]=='X' && board[i][j+1]=='X') inter.pb({i, j});
	}
	// debug(numBoard);
	forn(i, 0, r-1) {
		if (!vis[i][0] && board[i][0] == '.') outer += dfs(i, 0, 1);
		if (!vis[i][c-1] && board[i][c-1] == '.') outer += dfs(i, c-1, 1);
	}
	forn(j, 0, c-1) {
		if (!vis[0][j] && board[0][j] == '.') outer += dfs(0, j, 1);
		if (!vis[r-1][j] && board[r-1][j] == '.') outer += dfs(r-1, j, 1);
	}
	// debug(outer);
	vi test;
	forn(i, A.st-1, A.st + 1) forn(j, A.nd-1, A.nd+1) {
		if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j] || board[i][j] != '.') continue;
		int res = dfs(i, j);
		test.pb(res);
	}
	memset(vis, 0, sizeof vis);
	vi test2;
	forn(i, B.st-1, B.st + 1) forn(j, B.nd-1, B.nd+1) {
		if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j] || board[i][j] != '.') continue;
		int res = dfs(i, j);
		test2.pb(res);
	}
	if (sz(test) == 1 && sz(test2) == 1) {
		// debug("1");
		cout << test.back() << ' ' << test2.back() << 
			' '<< r * c - numBoard - outer - test.back() - test2.back() << '\n';
	} else if (sz(test) == 2 && sz(test2) == 1) {
		// debug("2");
		int ans1 = r * c - outer - numBoard - test[0] - test[1];
		int mid = test[0] + test[1] - test2[0];
		cout << ans1 << ' ' << test2[0] << ' ' << mid  << '\n';
	} else if (sz(test) == 1 && sz(test2) == 2) {
		// debug("3");
		int mid = test2[0] + test2[1] - test[0];
		int ans1 = test2[0] + test2[1] - mid;
		int ans2 = r * c - outer - numBoard - mid - ans1;
		cout << ans1 << ' ' << ans2 << ' ' << mid  <<'\n';
	} else {
		// debug("4");
		memset(vis, 0, sizeof vis);
		vi fin;
		pi p = inter[0];
		forn(i, p.st-1, p.st + 1) forn(j, p.nd-1, p.nd+1) {
			if (i < 0 || j < 0 || i >= r || j >= c || vis[i][j] || board[i][j] != '.') continue;
			int res = dfs(i, j);
			fin.pb(res);
		}
		int mid = accumulate(all(test), 0) + accumulate(all(test2), 0) - accumulate(all(fin), 0);
		int ans1 = accumulate(all(test2), 0)  - mid;
		int ans2 = accumulate(all(test), 0) - mid;
		cout << ans1 << ' ' << ans2  << ' ' << mid<<"\n";
	}

	return 0;
}
