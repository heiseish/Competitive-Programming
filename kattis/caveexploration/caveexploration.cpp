#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<unordered_map<int, bool> > rg;
vector<bool> e;
vector<int> l;
vector<int> c;
vector<int> p;
int ct = 0;

void DFS(int u) {
	e[u] = true;
	l[u] = c[u] = ct++; // preoder tranversal
	for (auto v : g[u]) {
		if (!e[v]) {
			p[v] = u;
			DFS(v);
			//Post order check from here
			l[u] = min(l[u], l[v]);
			if (l[v] >= c[u]) { 
				rg[u][v] = false;
				rg[v][u] = false;
			}
		} else if (p[u] != v) { //implying a back edge to ancestors of the node
			l[u] = min(l[u], c[v]);
		}
	}
}
int res = 0;
void DFSCount(int u) {
	res++;
	e[u] = true;
	for (auto v : g[u]) {
		if (!rg[u][v] || !rg[v][u]) continue;
		if (!e[v]) DFSCount(v);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	g.assign(n, {});
	rg.assign(n, {});
	e.assign(n, false);
	l.assign(n, -1);
	c.assign(n, -1);
	p.assign(n, -1);
	for (int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		rg[u][v] = true;
		rg[v][u] = true;
	}
	DFS(0);
	e.assign(n, false);
	DFSCount(0);
	cout << res << endl;
	return 0;
}