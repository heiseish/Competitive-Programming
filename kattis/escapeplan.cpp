/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
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
#define MAX 200003
#define NIL 0
unordered_map<int, vi> G;
int n, m;
vi match, dist;
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]
bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

double take(pair<double, double>& lhs, pair<double, double>& rhs) {
	return sqrt(pow(lhs.st - rhs.st, 2) + pow(lhs.nd - rhs.nd, 2)) / 10.0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int ct = 1;
	while(cin >> n  && n) {
		vector<pair<double, double> > r(n+1);
		forn(i,1,n) cin>>r[i].st>>r[i].nd;
		cin>>m;
		vector<pair<double, double> > h(m+1);
		forn(i,1,m) cin>>h[i].st>>h[i].nd;

		vector<double> poss = {5.0, 10.0, 20.0};
		match.resize(n + m + 1);
		dist.resize(n + m + 1);
		cout << "Scenario " << ct << '\n';
		for (auto &t : poss) {
			G.clear();
			forn(i,1,n) forn(j,1,m) {
				if (take(r[i], h[j]) <= t) {
					G[i].pb(n + j);
					G[n + j].pb(i);
				}
			}
			match.assign(n + m + 1, 0);
			int ans = hopcroft_karp();
			cout << "In " << (int) t << " seconds " << ans << " robot(s) can escape\n";
		}
		ct++;
		cout <<'\n';

	}
	
	return 0;
}
