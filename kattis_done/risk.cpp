/** 
you can do it too because you are not a failure like me.        
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
const int maxn = 103;
int a[maxn], b[maxn], r[maxn][maxn];
int N;
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
        long long f = 0;
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

	bool check() {
		for (auto &e : edges) {
			if (e.u == t && e.flow < e.cap) return true;
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		memset(b, 0, sizeof b);
		cin>>N;
		forn(i,1,N) cin>>a[i];
		forn(i,1,N) {
			string s;
			cin>>s;
			forn(j,1,N) {
				r[i][j] = s[j-1] == 'Y' ? 1 : 0;
				
			}
		}
		forn(i,1,N) forn(j,i+1,N) {
			if (r[i][j] && a[i] == 0 && a[j] != 0) b[j]++;
			if (r[i][j] && a[j] == 0 && a[i] != 0) b[i]++;
		}

		int source= 0, sink = 2 * N + 1;
		Dinic dn(2 * N + 2, source, sink);
		forn(i,1,N) if(a[i])  {
			dn.add_edge(source, i, a[i] - 1);
			dn.add_edge(i, i + N, a[i]);
		}
		forn(i,1,N) forn(j,i+1,N) {
			if (a[i] && a[j] && r[i][j]) {
				dn.add_edge(i + N, j, INF);
				dn.add_edge(j + N, i, INF);
			}
		}
		int lo = 0, hi = 10000;
		while(lo + 1 < hi) {
			int mid = (lo + hi)>>1;
			Dinic temp = dn;
			forn(i,1,N) if (b[i]) temp.add_edge(i, sink, mid);
			temp.flow();
			if (temp.check()) hi = mid;
			else lo = mid;
		}
		cout << lo  + 1<<'\n';
		
	}
	return 0;
}
