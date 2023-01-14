/** 
When a man learns to love, he must bear the risk of hatred.        
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
const int maxn = 6;
int board[maxn][maxn], fin[maxn][maxn];
bool can = false;
int step = INF;
void backtrack(int x, int y, int depth) {
	if (depth >= 11) return;
	if (memcmp(board, fin, sizeof board) == 0) {
		step = min(step, depth);
		return;
	}
	if (x >= 2 && y >= 1) {
		swap(board[x][y], board[x-2][y-1]);
		backtrack(x - 2, y - 1, depth + 1);
		swap(board[x][y], board[x-2][y-1]);
	}
	if (x >= 2 && y <= 3) {
		swap(board[x][y], board[x-2][y+1]);
		backtrack(x - 2, y + 1, depth + 1);
		swap(board[x][y], board[x-2][y+1]);
	}
	if (x >= 1 && y >= 2) {
		swap(board[x][y], board[x-1][y-2]);
		backtrack(x - 1, y - 2, depth + 1);
		swap(board[x][y], board[x-1][y-2]);
	}
	if (x >= 1 && y <= 2) {
		swap(board[x][y], board[x-1][y+2]);
		backtrack(x - 1, y + 2, depth + 1);
		swap(board[x][y], board[x-1][y+2]);
	}
	if (x <= 2 && y >= 1) {
		swap(board[x][y], board[x+2][y-1]);
		backtrack(x + 2, y - 1, depth + 1);
		swap(board[x][y], board[x+2][y-1]);
	}
	if (x <= 2 && y <= 3) {
		swap(board[x][y], board[x+2][y+1]);
		backtrack(x + 2, y + 1, depth + 1);
		swap(board[x][y], board[x+2][y+1]);
	}
	if (x <= 3 && y >= 2) {
		swap(board[x][y], board[x+1][y-2]);
		backtrack(x + 1, y - 2, depth + 1);
		swap(board[x][y], board[x+1][y-2]);
	}
	if (x <= 3 && y <= 2) {
		swap(board[x][y], board[x+1][y+2]);
		backtrack(x + 1, y + 2, depth + 1);
		swap(board[x][y], board[x+1][y+2]);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	forn(i,0,4) forn(j,i,4) fin[i][j] = 1;
	fin[2][2] = 2;
	fin[3][3] = 0;
	fin[4][4] = 0;
	int tc;
	cin>>tc;
	cin.ignore();
	while(tc--) {
		string s;
		int x, y;
		forn(i,0,4) {
			getline(cin, s);
			forn(j,0,4) {
				if (s[j] == ' ') {
					board[i][j] = 2;
					x = i; y = j;
				} else board[i][j] = (int) (s[j] - '0');
			}
		}
		can = false;
		step = INF;
		backtrack(x, y, 0);
		if (step > 11) cout << "Unsolvable in less than 11 move(s).\n";
		else cout << "Solvable in " << step << " move(s).\n";
	}
	return 0;
}
