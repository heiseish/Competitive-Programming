/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.
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
const int maxn = 17;
int b[maxn];
const int maxt = 3600 +3;
int e[maxt];
int n, t;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int c;
	scanf("%d", &c);
	while(c--) {
		memset(e, -1, sizeof e);
		scanf("%d %d", &n, &t);
		forn(i, 0, n - 1) scanf("%d", &b[i]);
		unordered_map<int, vi> g;
		forn(i, 0, 3600) {
			forn(j, 0, n - 1) {
				g[i].pb(min(max(i + b[j], 0), 3600));
			}
		}
		queue<pi> q;
		q.push({ 0, 0 });
		int ansStep = inf, ansDif = inf;
		while(!q.empty()) {
			pi cur = q.front(); q.pop();
			// debug(cur.st);
			// debug(cur.nd);
			if (cur.nd == t) {
				ansStep = cur.st;
				ansDif = 0;
				break;
			}
			if (cur.nd >= t && abs(cur.nd - t) < abs(ansDif)) {
				ansDif = abs(cur.nd - t);
				ansStep = cur.st;
			}
			for (auto i : g[cur.nd]) {
				if (e[i] == -1) {
					q.push({ cur.st + 1, i });
					e[i] = 1;
				}	
			}
		}
		printf("%d %d\n", ansStep, ansDif);
	}
	return 0;
}
