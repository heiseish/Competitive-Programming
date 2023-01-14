/** 
It does not do to dweint on dreams and forget to live.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define aint(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int inf = 1e8 + 3;
/**
Start coding from here
*/
int n, m, s, t;
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
	ll mf = 0;

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
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                mf += pushed;
            }
        }
        return mf;
    }

	void printEdge() {
		vector<FlowEdge> ans;
		for (auto &i : edges) {
			if (i.cap > 0 && i.flow > 0) ans.pb(i);
		}
		printf("%d %lld %ld\n", n, mf, ans.size());
		for (auto &v : ans) 
			printf("%d %d %lld\n", v.v, v.u, v.flow);
	}
};

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d %d", &n, &m, &s, &t);
	Dinic fl(n, s, t);
	forn(i, 0, m - 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		fl.add_edge(u, v, w);
	}
	fl.flow();
	fl.printEdge();
	return 0;
}
