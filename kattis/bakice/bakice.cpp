/** 
you can do it too because you are not a failure like me.        
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
const double EPS=1e-9;
struct ed {
	pi s, i;
	double dist;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int r, c;
	cin>>r>>c;
	vector<string> b(r);
	forn(i,0,r-1) cin>>b[i];
	vector<pi> seats, idiots;
	forn(i,0,r-1) forn(j,0,c-1) {
		if (b[i][j] == 'L') seats.pb({i, j});
		if (b[i][j] == 'X') idiots.pb({i, j});
	}
	vector<ed> g;
	for (auto &s : seats) for (auto &i : idiots) {
		g.pb({s, i, hypot(s.st-i.st, s.nd-i.nd)});
	}
	int ans = 0;
	sort(all(g), [](const ed& lhs, const ed& rhs) {
		return lhs.dist < rhs.dist;
	});
	forn(i,0,sz(g)-1){
		if (b[g[i].s.st][g[i].s.nd] == '.' || b[g[i].i.st][g[i].i.nd] == '.') continue;
		vector<ed> m(1, g[i]);
		while(i < sz(g) - 1 && abs(g[i+1].dist - g[i].dist) < EPS) {
			i++;
			if (b[g[i].s.st][g[i].s.nd] == '.' || b[g[i].i.st][g[i].i.nd] == '.') continue;
			m.pb(g[i]);	
		}
		sort(all(m), [](const ed&lhs, const ed& rhs) {
			return lhs.s < rhs.s;
		});
		
		forn(i,0,sz(m)-1) {
			bool can = false;
			pi cur = m[i].s;
			if (b[cur.st][cur.nd] != 'L') continue;
			while( i< sz(m) - 1 && m[i+1].s == cur) {
				if (b[m[i+1].i.st][m[i+1].i.nd] == '.') continue;
				b[m[i+1].i.st][m[i+1].i.nd] = '.';
				can = true;
				i++;
			}
			b[cur.st][cur.nd] = '.';
			if (can) ans++;
		}
	}
	cout << ans<<'\n';
	return 0;
}
