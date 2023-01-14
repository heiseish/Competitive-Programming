#include <bits/stdc++.h>
#define vv vector<vector<char> >
using namespace std;

bool check(vv& graph, int i, int j, int N, int M, int k) {
	char m=graph[i][j];

	int currentI = i;
	int count = 1;
	while (--currentI >= 0 && graph[currentI][j] == m) {
		count++;
	}
	if (count >= k) return true;

	int currentJ = j;
	count = 1;
	while (--currentJ >= 0 && graph[i][currentJ] == m) {
		count++;
	}
	if (count >= k) return true;

	currentI = i;
	currentJ = j;
	count = 1;
	while (--currentJ >= 0 && --currentI >= 0 && graph[currentI][currentJ] == m) {
		count++;
	}
	if (count >= k) return true;
	

	currentI = i;
	currentJ = j;
	count = 1;
	while (currentJ++ < M && --currentI >= 0 && graph[currentI][currentJ] == m) {
		count++;
	}
	if (count >= k) return true;
	return false;
}
int main() {
	int l, h=0, g=0;
	cin >> l;
	for (int i=0;i<l;i++) {
		int M, N, K;
		cin >> M >> N >> K;
		vv graph(N, vector<char>(M, '.'));
		int winner = 0;
		for (int n=0;n<N;n++) {
			for (int m=0;m<M;m++){
				cin >> graph[n][m];
				if (winner == 0) {
					if (graph[n][m] == 'x' && check(graph, n, m, N, M, K)) winner = 1;
					if (graph[n][m] == 'o' && check(graph, n, m, N, M, K)) winner = 2;
				}
				
			}
		}
		if (winner == 1) h++;
		if (winner == 2) g++;
	}
	cout << h << ":" << g << endl;
	return 0;
}