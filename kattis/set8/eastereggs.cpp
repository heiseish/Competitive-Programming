/** 
Hard work is worthless for those that don’t believe in themselves.        
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
int N, B, R;
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


double distance(pi& lhs, pi& rhs) {
	return sqrt(pow(lhs.st - rhs.st, 2) + pow(lhs.nd - rhs.nd, 2));
}

bool cmp(pair<double, pi>& lhs, pair<double, pi>& rhs) {
	return lhs.st > rhs.st;
}

const int maxn = 253;
pi b[maxn], r[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>N>>B>>R;
	n = B, m = R;
	forn(i,1,B) cin>>b[i].st>>b[i].nd;
	forn(i,1,R) cin>>r[i].st>>r[i].nd;
	vector<pair<double, pi> > c;
	forn(i,1,B) forn(j,1,R) {
		c.pb({distance(b[i], r[j]), {i, j}});
	}
	sort(all(c));
	// for (auto &v : c) debug(v.st);

	int lo = -1, hi = sz(c);
	dist.assign(n+ m + 1, 0);
	while(lo + 1 < hi) {
		int mid = (lo + hi) >>1;
		G.clear();
		match.assign(n + m + 1, NIL);
		forn(i,0,mid) {
			G[c[i].nd.st].pb(n + c[i].nd.nd);
		}
		int hk = hopcroft_karp();
		int ans = B + R - hk;
		if (ans >= N) lo = mid;
		else hi = mid;
	}
	cout << fixed << setprecision(15) << c[hi].st <<'\n';
	return 0;
}
