#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int r[N];
int no[N];
int perm[15][N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &perm[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		no[perm[1][i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			perm[i][j] = no[perm[i][j]];
		}
	}
	for (int i = 1; i <= n; i++) {
		r[i] = n - i + 1;
	}

	for (int  i = 1; i <= m; i++) {
		int cur = 1;
		for (int j = 1; j <= n; j++) {
			if (cur < j) cur++;
			while(cur < n && perm[i][cur + 1] == perm[i][cur] + 1) cur++;
			r[perm[i][j]] = min(r[perm[i][j]], cur - j + 1);
		}
	}
	ll ct = 0;
	for (auto i : r) {
		ct += 1LL * i;
	}
	cout << ct << endl;
	return 0;
}