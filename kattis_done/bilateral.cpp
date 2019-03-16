/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
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
vi G[2005];
const int NIL = 0;

int n = 2000, m;
vi match, dist;

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
            if(match[i]==NIL && dfs(i))  matching++;
                
    return matching;
}
const int OFFSET = 999;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	unordered_map<int, int> idtoi, itoid;
	cin>>m;
	int a, b;
	forn(i,1,m) {
		cin>>a>>b;
		a-=OFFSET;
		b-=OFFSET;
		// if (a > b) swap(a, b);
		G[a].pb(b);
		G[b].pb(a);
	}
	match.assign(n + 1, 0); dist.assign(n + 1, 0);
	cout << hopcroft_karp() << '\n';
	vi allright(n+1, 0);
	while(true) {
		bool can = false;
		forn(i,1,n) {
			for (auto &v : G[i]) {
				if (match[i] == NIL && match[v] != NIL && allright[v] == 0) {
					allright[v]=1;
					match[match[v]] = NIL;
					can = true;
				}
			}
		}
		if (!can) break;
	}
	forn(i,1,n)
		if (match[i] != NIL && !allright[i] && !allright[match[i]]) 
			allright[i] = 1;
	forn(i,1,n) if (allright[i]) cout << i  + OFFSET  << '\n';
	return 0;
}
