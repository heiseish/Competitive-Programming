/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxs = 2e3 + 3;
char board[maxs][maxs];
int R, C;

int moves[8] = {-1, 0, 1, 0, 0, 1, 0, -1};
struct State {
	int m;
	int p;
	int x, y;
};
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &C, &R);
		forn(i, 0, R - 1) scanf("%s", board[i]);
		queue<State> q;
		State s;
		vector<State> f;
		forn(i, 0, R - 1)
			forn(j, 0, C - 1) {
				if (board[i][j] == '@')
					s = {0, 1, i, j};
				if (board[i][j] == '*')
					f.pb({0, 0, i, j});
			}
		q.push(s);
		for (auto i : f) q.push(i);
		int ans = inf;
		while(!q.empty()){
			State cur = q.front();q.pop();
			if (cur.p) {
				if (board[cur.x][cur.y] == '*') continue;
				if ((cur.x == 0 || cur.x == R - 1 || cur.y == 0 || cur.y == C - 1)) {
					ans = cur.m + 1;
					break;
				}
				forn(i, 0, 3) {
					int nx = cur.x + moves[2 * i];
					int ny = cur.y + moves[2 * i + 1];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (board[nx][ny] == '.') {
						board[nx][ny] = '@';
						q.push({cur.m + 1, 1, nx, ny});
					}
						
				}
			} else {
				forn(i, 0, 3) {
					int nx = cur.x + moves[2 * i];
					int ny = cur.y + moves[2 * i + 1];
					if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if (board[nx][ny] == '.' || board[nx][ny] == '@') {
						board[nx][ny] = '*';
						q.push({cur.m + 1, 0, nx, ny});
					}
						
				}
			}
		}
		if (ans == inf) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);

	}
	return 0;
}
