/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
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
const int maxm = 203;
const int maxn = 23;
int in[maxm][maxn], ans[maxm][maxn], add[maxm][maxn];
int am[maxm], testm[maxm], AM[maxm];
int an[maxn], testn[maxn], AN[maxn];
int M, N;
int TC;
vector<pair<char, int> > QQ[maxm][maxn];

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

	void answer() {
		/**
		Assign flow edge to the answer matrix
		*/
		for (auto &e : edges) {
			if (e.v >= 1 && e.v <= M && e.u >= M + 1 && e.u <= M + N && ans[e.v][e.u - M] == -1) {
				ans[e.v][e.u - M] = e.flow;
			}
		}
	}
};


inline bool makeMore(int i, int j, int k) {
	/**
	Adjust flow edge to fit constraint
	*/
	if (k + 1 > am[i] || k + 1 > an[j]) return false;
	add[i][j] = max(add[i][j], k + 1);
	am[i] -= add[i][j];
	an[j] -= add[i][j];
	if (am[i] < 0 || an[j] < 0) return false;
	return true;
}

inline bool makeLess(int i, int j, int k) {
	/**
	Adjust flow edge to fit constraint
	*/
	in[i][j] = min(in[i][j], k - 1 - add[i][j]);
	if (in[i][j] < 0) return false;
	return true;
}


inline bool makeEqual(int i, int j, int k) {
	/**
	Adjust flow edge to fit constraint
	*/
	if (k > am[i] || k > an[j] || 
		(ans[i][j] != -1 && ans[i][j] != k)) return false;
	if (ans[i][j] == k) return true;

	in[i][j] = 0;
	ans[i][j] = k;
	am[i] -= k;
	an[j] -= k;
	if (am[i] < 0 || an[j] < 0) return false;
	return true;
}

void print(int tc) {
	/**
	Print answer matrix
	*/
	forn(i,1,M) {
		forn(j,1,N) {
			cout << ans[i][j] <<' ';
		}
		cout <<'\n';
	}
	if (tc != TC) cout <<'\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	
	cin>>TC;
	forn(tc, 1, TC) {
		cin>>M>>N;
		// AM and AN are used to test later
		forn(i,1,M) {
			cin>>am[i];
			AM[i] = am[i];
		}
		forn(i,1,N) {
			cin>>an[i];
			AN[i] = an[i];
		}
		
		
		//Clear matrix
		forn(i,1,M) forn(j,1,N) {
			in[i][j] = INF;
			ans[i][j] = -1;
			add[i][j] = 0;
			QQ[i][j].clear();
		}
		int k;
		cin>>k;
		
		forn(i,0,k-1) {
			int a,b,c;
			char ch;
			cin>>a>>b>>ch>>c;
			/**
			Push contraints for each cell
			*/
			if (a == 0 && b == 0) {
				forn(i,1,M) forn(j,1,N) QQ[i][j].pb({ch, c});
			} else if (a == 0) {
				forn(i,1,M) QQ[i][b].pb({ch, c});
			} else if (b == 0) {
				forn(i,1,N) QQ[a][i].pb({ch, c}); 
			} else QQ[a][b].pb({ch, c});
		}

		bool can = true;

		/**
		Add constraints to flow edge
		matrix IN[i][j] is the flowedge value of cell at row i and column j
		*/
		forn(i,1,M) forn(j,1,N) {
			int lessthan = INF;
			int morethan = -1;
			int equal = -1;
			for (auto &v : QQ[i][j]) {
				if (v.st == '<') {
					lessthan = min(lessthan, v.nd);
				} else if (v.st == '=') {
					if (equal == -1) equal = v.nd;
					else if (equal != v.nd) can = false;
				} else {
					morethan = max(morethan, v.nd);
				}
			}
			if (morethan >= lessthan - 1) {
				can = false;
				break;
			}
			
			if (equal == -1) {
				can &= makeMore(i, j, morethan);
				can &= makeLess(i, j, lessthan);
			} else {
				if (equal >= lessthan || equal <= morethan) can = false;
				can &= makeEqual(i, j, equal);
			}
		}
		if (!can) {
			cout << "IMPOSSIBLE\n";
			if (tc != TC) cout <<'\n';
			continue;
		}


		//Dinic
		int SOURCE = 0, SINK = M + N + 1;
		Dinic dn(M + N + 2, SOURCE, SINK);
		forn(i,1,M) dn.add_edge(SOURCE, i, am[i]);
		forn(i,1,N) dn.add_edge(M + i, SINK, an[i]);
		forn(i,1,M) forn(j,1,N) dn.add_edge(i, M + j, in[i][j]);
		

		// Add answer with add matrix which store the minimum values of the cells ealier;
		// testm and testn to check values of m rows and n columns
		dn.flow();
		dn.answer();
		memset(testm, 0, sizeof testm);
		memset(testn, 0, sizeof testn);
		forn(i,1,M) {
			forn(j,1,N) {
				ans[i][j] += add[i][j];
				testm[i] += ans[i][j];
				testn[j] += ans[i][j];
			}
		}
		forn(i,1,M) if (testm[i] != AM[i]) can = false;
		forn(i,1,N) if (testn[i] != AN[i]) can = false;

		if (!can) {
			cout << "IMPOSSIBLE\n";
			if (tc != TC) cout <<'\n';
			continue;
		}
		print(tc);
		

	}
	return 0;
}
