/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.        
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
int M, N;
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

	vector<vi> getAns(int &count) {
		vector<vi> ans(N + 1);
		vi track(M + 1, 0);
		for (auto &e : edges) {
			if (e.v >= 1 && e.v <= N && e.u >= N + 1 && e.u <= N + M && e.flow  > 0) {
				ans[e.v].pb(e.u-N);
				track[e.u - N]++;
			}	
		}
		count = *max_element(all(track));
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	
	cin>>M>>N;
	int SOURCE = 0, SINK = M + N + 1;
	Dinic dn(M + N + 2, SOURCE, SINK);
	vector<string> names(M + 1);
	forn(i,1,M) {
		int k;
		cin>>names[i] >> k;
		forn(j,1,k) {
			int a;
			cin>>a;
			dn.add_edge(a, N + i, 1);
		}
	}
	forn(i,1,N) dn.add_edge(SOURCE, i, 2);
	int lo = 0, hi = N;
	vector<vi> fin;
	int count = 0;
	while(lo + 1 < hi) {
		int mid = (lo + hi) >> 1;
		Dinic temp = dn;
		forn(i,1,M) temp.add_edge(i + N, SINK, mid);
		temp.flow();
		fin = temp.getAns(count);
		bool can = true;
		forn(i,1,N) {
			if (sz(fin[i]) < 2) {
				can = false;
				break;
			}
		}
		if (can) hi = mid;
		else lo = mid;
	}
	forn(i,1,M) dn.add_edge(i + N, SINK, hi);
	dn.flow();
	fin = dn.getAns(count);
	cout << count <<'\n';
	forn(i,1,N) {
		cout << "Day " << i << ": ";
		cout << names[fin[i][0]] << ' ' << names[fin[i][1]] <<'\n';
	}
	
	return 0;
}
