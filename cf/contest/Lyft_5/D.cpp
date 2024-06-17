#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 1000 + 5;
typedef vector<int> vi;
typedef unordered_map<int, vi> mivi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
mivi graph;
vi subgA, subgB;
int n;

int inquire(char tree, int index) {
	printf("%c %d\n", tree, index);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	if (res == -1) exit(0);
	return res;
}

vii BFS(int source) {
	queue<ii> q;
	bool explored[MAXSIZE] = { false };
	explored[source] = true;
	q.push({ 0, source});
	vii res;
	bool done = false;
	while (!q.empty()) {
		ii item = q.front();q.pop();
		explored[item.second] = true;
		for (auto i : graph[item.second]) {
			if (explored[i]) continue;
			if (subgA[i]) {
				res.push_back({ item.first + 1, i });
			}
			q.push({ item.first + 1, i});
		}
	}
	return res;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		graph.clear();
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++ ) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int k1, k2;
		scanf("%d", &k1);
		subgA.assign(n + 1, 0);
		for (int i = 0; i < k1; i++) {
			int temp;
			scanf("%d", &temp);
			subgA[temp]  = 1;
		}
		scanf("%d", &k2);
		int startB  = -1;
		subgB.assign(n + 1, 0);
		for (int i = 0; i < k2; i++) {
			int temp;
			scanf("%d", &temp);
			if (startB == -1) startB = temp;
			subgB[temp]  = 1;
		}


		int start = inquire('B', startB);
		if (subgA[start]) {
			printf("C %d\n", start);
			fflush(stdout);
		} else {
			bool can = false;
			vii checkVertices = BFS(start);
			int MIN = -1;
			for (auto i : checkVertices) {
				int weight = i.first, idx = i.second;
				if (MIN == -1) MIN = weight;
				if (weight > MIN) break;
				int ans = inquire('A', idx);

				if (subgB[ans]) {
					printf("C %d\n", idx);
					fflush(stdout);
					can = true;
					break;
				}
			}
			if (!can) {
				printf("C -1\n");
				fflush(stdout);
			}
		}
	}
	return 0;
}