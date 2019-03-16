/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		int s;
		cin>>s;
		char ch;
		pi st{0,0};
		map<pi, int> k;
		k[st] = 0;
		int ct = 1;
		unordered_map<int, vi> g;
		int fin = -1;
		forn(i,1,s) {
			cin>>ch;
			pi nxt = st;
			if (ch == 'N') nxt.nd++;
			if (ch == 'E') nxt.st++;
			if (ch == 'S') nxt.nd--;
			if (ch == 'W') nxt.st--;
			if (!k.count(nxt)) 
				k[nxt] = ct++;
			int a = k[nxt];
			int b = k[st];
			if (i==s) 
				fin=a;
			g[a].pb(b);
			g[b].pb(a);
			st = nxt;
		}
		queue<pi> q;
		q.push({0, 0});
		vi vis(ct, 0);
		vi dist(ct, INF);
		dist[0] = 0;
		while(!q.empty()) {
			auto f = q.front(); q.pop();
			dist[f.st] = f.nd;
			vis[f.st]++;
			for (auto &v : g[f.st]) {
				if (!vis[v]) {
					q.push({v, f.nd + 1});
				}
			}
		}
		cout << dist[fin] << '\n'

	}
	return 0;
}
