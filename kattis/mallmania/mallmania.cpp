/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone
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
const int maxn = 2e3 + 3;
int d[maxn][maxn];
int s, e;
int dist(pi lhs, pi rhs) {
	return abs(lhs.st - rhs.st) + abs(lhs.nd - rhs.nd);
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d", &s) && s) {
		memset(d, -1, sizeof d);
		queue<pi> q;
		forn(i, 0, s - 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			d[x][y] = 0;
			q.push({x, y});

		}
		scanf("%d", &e);
		forn(i, 0, e - 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			d[x][y] = -2;
		}
		int ans;
		while(!q.empty()) {
			pi cur = q.front();q.pop();
			auto [x, y] = cur;

			if (x < maxn - 1) {
				if (d[x + 1][y] == -1) {
					q.push({x + 1, y});
					d[x + 1][y] = d[x][y] + 1;
				} else if (d[x + 1][y] == -2) {
					ans = d[x][y] + 1;
					break;
				}
			}
			
			if (y < maxn - 1) {
				if (d[x][y+1] == -1) {
					q.push({x, y+1});
					d[x][y+1] = d[x][y] + 1;
				} else if (d[x][y+1] == -2) {
					ans = d[x][y] + 1;
					break;
				}
			}
			if (x > 0) {
				if (d[x-1][y] == -1) {
					q.push({x-1, y});
					d[x-1][y] = d[x][y] + 1;
				} else if (d[x-1][y] == -2) {
					ans = d[x][y] + 1;
					break;
				}
			}

			if (y > 0) {
				if (d[x][y-1] == -1) {
					q.push({x, y-1});
					d[x][y-1] = d[x][y] + 1;
				} else if (d[x][y-1] == -2) {
					ans = d[x][y] + 1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
