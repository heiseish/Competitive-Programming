/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.
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
vi hl, hi;
unordered_map<int, vi> g;
void solve() {
	queue<int> q;
	for (auto i : hl) {
		q.push(i);
		hi[i] = 0;
	}
	while(!q.empty()) {
		int cur = q.front();q.pop();
		for (auto i : g[cur]) {
			if (hi[i] == inf) {
				hi[i] = hi[cur] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, h, l;
	scanf("%d %d %d", &n, &h, &l);
	hl.resize(h);
	hi.assign(n, inf);
	forn(i, 0, h - 1) scanf("%d", &hl[i]);
	forn(i, 1, l) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	solve();
	int maxhi = 0;
	int maxidx = -1;
	forn(i, 0, n - 1) {
		if (hi[i] > maxhi) {
			maxhi = hi[i];
			maxidx = i;
		}
	}
	printf("%d\n", maxidx);
	return 0;
}
