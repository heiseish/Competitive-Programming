/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.
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
const int maxn = 1e4 + 7;
int P, T;
unordered_map<int, vpi> g;
vector<vpi> subg;
int d[maxn], e[maxn] = { 0 };
void djikstra(int index) {
	// d.assign(P, inf);
	forn(i, 0, P - 1)
		d[i] = inf;
	priority_queue<pi, vpi, greater<pi> > pq;
	d[0] = 0;
	pq.push({0, 0});
	while(!pq.empty()) {
		pi cur = pq.top(); pq.pop();
		auto [dist, u] = cur;
		if (dist > d[u]) continue;
		for (auto v : g[u]) {
			if (d[v.nd] > d[u] + v.st) {
				subg[v.nd].clear();
				subg[v.nd].pb({v.st, u});
				d[v.nd] = d[u] + v.st;
				pq.push({ d[v.nd], v.nd });
			} else if (d[v.nd] == d[u] + v.st) {
				subg[v.nd].pb({v.st, u});
			}
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d", &P, &T);
	subg.assign(P, {});
	forn(i, 0, T - 1) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		g[a].pb({l, b});
		g[b].pb({l, a});
	}
	djikstra(0);
	int ans = 0;
	queue<pi> res;
	res.push({0, P - 1});
	while(!res.empty()) {
		pi cur = res.front(); res.pop();
		auto [dist, u] = cur;
		for (auto i : subg[u]) {
			ans += i.st;
			if (!e[i.nd]) {
				res.push(i);
				e[i.nd] = 1;
			}
			
		}
	}
	printf("%d\n", ans * 2);
	return 0;
}
