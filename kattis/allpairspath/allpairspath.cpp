#include <bits/stdc++.h>
#define forn(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int inf = 5e8 + 3;
const int maxn = 153;
int graph[maxn][maxn];
int main() {
	int n, m , q;
	while (scanf("%d %d %d", &n, &m, &q) && (n || m || q)) {
		forn(i, 0, n - 1)
			forn(j, 0, n - 1)
				graph[i][j] = (i == j) ? 0 : inf;

		for (int i = 0;i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			graph[u][v] = min(w, graph[u][v]);
		}
        

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}

		// Check for negative cost cycle
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					if(graph[k][k] < 0 && graph[i][k] != inf && graph[k][j] != inf) graph[i][j] = -inf;
				}
			}
		}

		for (int i = 0; i < q; i++) {
			int u, v;
			scanf("%d %d", &u, &v);

			if (graph[u][v] == inf) {
				printf("Impossible\n");

			} else if (graph[u][v] == -inf) {
				printf("-Infinity\n");
			} else {
				printf("%d\n", graph[u][v]);
			}
		}
	}
	return 0;
}