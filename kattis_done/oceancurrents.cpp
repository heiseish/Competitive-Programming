/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.
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
const int maxn = 1e3 + 3;
int l[maxn][maxn];
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int r, c;
    scanf("%d %d", &r, &c);
    vector<string> b(r);
    forn(i, 0, r - 1)
        cin >> b[i];
    int t;
    scanf("%d", &t);
    while(t--) {
		forn(i, 0, r - 1) 
			forn(j, 0, c-1)
				l[i][j] = inf;
        int rs, cs, rd, cd;
        scanf("%d %d %d %d", &rs, &cs, &rd, &cd);
        rs--;cs--;rd--;cd--;
        deque<pair<int, pi> > q;
        q.push_back({0, {rs, cs}});
		l[rs][cs] = 0;
        while(!q.empty()) {
            auto cur = q.front(); q.pop_front();
            auto [w, rhs] = cur;
            auto [x, y] = rhs;
            if (w > l[x][y]) continue;
            if (x == rd && y == cd) 
				break;
            if (x < r - 1) {
                if (b[x][y] == '4') {
					if (l[x+1][y] > w) {
						q.push_front({w, {x + 1, y}});
						l[x+1][y] = w;
					}
						
				} else {
					if (l[x+1][y] > w + 1) {
						q.pb({w + 1, {x + 1, y}});
						l[x+1][y] = w + 1;
					}
						
				}
            }
			if (x > 0) {
                if (b[x][y] == '0') {
					if (l[x-1][y] > w) {
						q.push_front({w, {x - 1, y}});
						l[x-1][y] = w;
					}
						
				} else {
					if (l[x-1][y] > w + 1) {
						q.pb({w + 1, {x - 1, y}});
						l[x-1][y] = w + 1;
					}
						
				}
            }
			if (y < c - 1) {
                if (b[x][y] == '2') {
					if (l[x][y+1] > w) {
						q.push_front({w, {x,  y+1}});
						l[x][y+1] = w;
					}
						
				} else {
					if (l[x][y+1] > w + 1) {
						q.pb({w + 1, {x , y+1}});
						l[x][y+1] = w + 1;
					}
						
				}
            }
			if (y > 0) {
                if (b[x][y] == '6') {
					if (l[x][y-1] > w) {
						q.push_front({w, {x , y-1}});
						l[x][y-1] = w;
					}
						
				} else {
					if (l[x][y-1] > w + 1) {
						q.pb({w + 1, {x , y-1}});
						l[x][y-1] = w + 1;
					}
						
				}
            }
			if (x > 0 && y > 0) {
                if (b[x][y] == '7') {
					if (l[x-1][y-1] > w) {
						q.push_front({w, {x - 1, y-1}});
						l[x-1][y-1] = w;
					}
						
				} else {
					if (l[x-1][y-1] > w + 1) {
						q.pb({w + 1, {x - 1, y-1}});
						l[x-1][y-1] = w + 1;
					}
						
				}
            }
			if (x > 0 && y < c - 1) {
                if (b[x][y] == '1') {
					if (l[x-1][y+1] > w) {
						q.push_front({w, {x - 1, y+1}});
						l[x-1][y+1] = w;
					}
						
				} else {
					if (l[x-1][y+1] > w + 1) {
						q.pb({w + 1, {x - 1, y+1}});
						l[x-1][y+1] = w + 1;
					}
						
				}
            }
			if (x > 0 && y < r - 1) {
                if (b[x][y] == '5') {
					if (l[x+1][y-1] > w) {
						q.push_front({w, {x + 1, y-1}});
						l[x+1][y-1] = w;
					}
						
				} else {
					if (l[x+1][y-1] > w + 1) {
						q.pb({w + 1, {x + 1, y-1}});
						l[x+1][y-1] = w + 1;
					}
						
				}
            }
			if (x < r - 1 && y < c - 1) {
                if (b[x][y] == '3') {
					if (l[x+1][y+1] > w) {
						q.push_front({w, {x + 1, y+1}});
						l[x+1][y+1] = w;
					}
						
				} else {
					if (l[x+1][y+1] > w + 1) {
						q.pb({w + 1, {x + 1, y+1}});
						l[x+1][y+1] = w + 1;
					}
						
				}
            }

        }
        printf("%d\n", l[rd][cd]);
    }
    return 0;
}