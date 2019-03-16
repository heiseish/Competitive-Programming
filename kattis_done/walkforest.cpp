/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
const int maxn = 1003;
int ways[maxn], dist[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	while(cin>>n>>m) {
		unordered_map<int, vpi> g;
		unordered_map<int, vi> ng;
		int a, b, d;
		forn(i,0,m-1) {
			cin>>a>>b>>d;
			g[a].pb({d, b});
			g[b].pb({d, a});
		}
		memset(dist, 0x3F3F3F3F, sizeof dist);
		dist[2]=0;
		priority_queue<pi, vpi, greater<pi> > q;
		q.push({0, 2});
		while(!q.empty()) {
			pi f = q.top(); q.pop();
			for (auto &v : g[f.nd]) {
				if (dist[v.nd] > dist[f.nd] + v.st) {
					dist[v.nd] = dist[f.nd] + v.st;
					q.push(v);
				}
			}
		}
		vpi k(n);
		forn(i,1,n) k[i-1] = {dist[i], i};
		sort(all(k));
		forn(i,1,n) {
			for (auto &v : g[i]) {
				if (dist[i] < dist[v.nd]) ng[i].pb(v.nd);
			}
		}
		memset(ways, 0, sizeof ways);
		ways[2]=1;
		forn(i,1,n) {
			for (auto &v : ng[k[i-1].nd]) {
				ways[v] += ways[k[i-1].nd];
			}
		}
		cout << ways[1] <<'\n';
	}
	return 0;
}
