/** 
When a man learns to love, he must bear the risk of hatred.
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
const int maxn = 10;
int e[maxn][maxn];
unordered_map<int, unordered_map<int, vpi> > g;
int hp = 0;
unordered_map<int, char> itl;
unordered_map<int, char> lti;

void bfs(int i, int j) {
	pi start(i, j);
	queue<pi> q;
	q.push(start);
	e[i][j] = 0;
	while(!q.empty()) {
		pi cur = q.front(); q.pop();
		for (auto p : g[cur.st][cur.nd]) {
			if (e[p.st][p.nd] == -1) {
				e[p.st][p.nd] = e[cur.st][cur.nd] + 1;
				if (e[p.st][p.nd] > hp) hp = e[p.st][p.nd];
				q.push(p);
			}
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	forn(i, 1, 8) itl[i] = 'a' + (i - 1);
	forn(i, 1, 8) lti['a' + (i - 1)] = i;
	forn(i, 1, 8)
		forn(j, 1, 8) {
			if (j >= 2 && i >= 3) g[i][j].pb({i - 2, j - 1});
			if (j >= 3 && i >= 2) g[i][j].pb({i - 1, j - 2});
			if (i <= 7 && j >= 3) g[i][j].pb({i + 1, j - 2});
			if (i <= 6 && j >= 2) g[i][j].pb({i + 2, j - 1});
			if (j <= 7 && i >= 3) g[i][j].pb({i - 2, j + 1});
			if (i >= 2 && j <= 6) g[i][j].pb({i - 1, j + 2});
			if (i <= 7 && j <= 6) g[i][j].pb({i + 1, j + 2});
			if (i <= 6 && j <= 7) g[i][j].pb({i + 2, j + 1});
		}
	while(t--) {
		hp = 0;
		memset(e, -1, sizeof e);
		string temp;
		cin >> temp;
		int jidx = lti[temp[0]], iidx = temp[1] - '0';
		bfs(iidx, jidx);
		vpi res;
		forn(i, 1, 8) {
			forn(j, 1, 8) {
				if (e[i][j] == hp) res.pb({i, 9 - j});
			}
		}
		sort(all(res), greater<pi>());
		printf("%d ", hp);
		for (auto i : res) {
			char jidx = itl[9 - i.nd];
			string temp = "";
			temp += jidx;
			temp += ('0' + i.st);
			printf("%s ", temp.c_str());
		}
		printf("\n");
	}
	return 0;
}
