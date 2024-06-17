#include <bits/stdc++.h>
using namespace std;
int inf = 1 << 30;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
	v[n] = pow(10, 9);
	sort(v.begin(), v.end());
	int curV = 0;
	vector<int> h;
	for (int i = 0; i < m; i++) {
		int x1, x2, y;
		scanf("%d %d %d", &x1, &x2, &y);
		if (x1 != 1) continue;
		h.push_back(x2);
	}
	m = h.size();
	sort(h.begin(), h.end());
	int MIN = inf;
	int curv = 0, curh = 0;
	while (curv != n + 1 && curh != m) {
		while(h[curh] < v[curv] && curh < m) curh++;
		if (m - curh + curv < MIN) {
			// cout << curh << " " << curv << endl;
			MIN = m - curh + curv;
		}
		curv++;
	}
	if (MIN == inf) printf("0\n");
	else printf("%d\n", MIN);
	return 0;
}