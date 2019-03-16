#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;
typedef vector<iiii> viiii;
int inf = 1 << 30;
int main() {
	int n,m,q, s;
	while(scanf("%d %d %d %d", &n, &m, &q, &s) && (n || m || q || s)) {
		unordered_map<int, viiii> g;
		for (int i = 0; i < m; i++) {
			int u, v, w, P, t;
			scanf("%d %d %d %d %d", &u, &v, &t, &P, &w);
			g[u].push_back({{ w, v}, {t, P}});
		}

		priority_queue<ii, vii, greater<ii> > qs;
		vector<int> d(n, inf);
		d[s] = 0;
		qs.push({0, s});
		while(!qs.empty()) {
			ii t = qs.top();
			qs.pop();
			if (t.first == d[t.second]) {
				for (auto i : g[t.second]) {
					int t0 = i.second.first, p = i.second.second;
					int w = i.first.first, v = i.first.second;
					if (t0 <t.first) t0 += p * ceil((t.first - t0) * 1.0/ p);

					if (d[v] > d[t.second] + w + t0 - t.first) {
						d[v] = d[t.second] + w + t0 - t.first;
						qs.push({ d[v], v});
					}
				}
			}
			
		}

		for (int  i = 0; i < q; i++) {
			int t;
			scanf("%d", &t);
			if (d[t] == inf) printf("Impossible\n");
			else printf("%d\n", d[t]);
		}
		printf("\n");
	}
	return 0;
}