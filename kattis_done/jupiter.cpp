/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
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

const ll INF = 1LL << 60;
/**
Start coding from here
*/
int N, Q, S;
const int MAXQ = 36;
int qsize[MAXQ], presink[MAXQ];
const int MAXS = 103;
int ss[MAXS];
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int> > adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0LL;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

inline int out(int i) {
    return i + Q * N;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    cin>>N>>Q>>S;
    forn(i,1,S) cin>>ss[i];
    forn(i,1,Q) cin>>qsize[i];

    int source = 0, sink = S + 2 * Q * N + N + 1;
    Dinic dn(S + 2 * Q * N + N + 2, source, sink);

    int st = sink - N;
    forn(i,1,N) presink[i] = st++;

    forn(i,1,S) dn.add_edge(source, i, INF);
    forn(i,1,Q) {
        for(int j = S + i, k = 1; k <= N; k++, j += Q) {
            dn.add_edge(j, out(j), qsize[i]);
            if (k < N) dn.add_edge(out(j), j + Q, qsize[i]);
        }
    }
    ll tot = 0LL;
    int cur = S + 1;
    forn(i,1,N) {
        ll d;
        cin>>d;
        dn.add_edge(presink[i], sink, d);
        ll a;
        forn(k,1,Q) dn.add_edge(out(cur++), presink[i], qsize[k]);
        forn(j,1,S) {
            cin >> a;
            tot += a;
            dn.add_edge(j, S + (i-1) * Q + ss[j], a);
        }
    }
    if (tot == dn.flow()) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}
