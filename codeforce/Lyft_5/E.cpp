#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int inf = 1 << 30;
int peri(ii x, ii y, ii z) {
	return abs(x.first - y.first) + abs(x.first - z.first)
	+ abs(y.first - z.first) + abs(x.second - y.second)
	+ abs(y.second - z.second) + abs(z.second - x.second); 
}
int main() {
	int n;
	scanf("%d", &n);
	ii def0 = {inf, inf};
	ii def1 = {-inf, -inf};
	vector<ii> ep(4);
	ep[0] = def0;
	ep[1] = def0;
	ep[2] = def1;
	ep[3] = def1;
	vector<ii> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
		if (p[i].first < ep[0].first) ep[0] = p[i];
		if (p[i].second < ep[1].second) ep[1] = p[i];
		if (p[i].first > ep[2].first) ep[2] = p[i];
		if (p[i].second > ep[3].second) ep[3] = p[i];
	}
	
	int FMAX = 2 * (ep[2].first - ep[0].first + ep[3].second - ep[1].second);
	int f3 = -inf;
	for (int i = 0; i < 4; i++) {
		for(int j = i + 1; j < 4; j++) {
			for (int k = 0; k < n; k++) {
				if (ep[i] == def0 || ep[i] == def1 ||
					ep[j] == def0 || ep[j] == def1)
				if (p[k] == ep[i] || p[k] == ep[j]) continue;
				if (peri(p[k], ep[i], ep[j]) > f3) f3 = peri(p[k], ep[i], ep[j]);
			}
		}
	}
	printf("%d ", f3);
	for (int i = 4; i <= n; i++) printf("%d ", FMAX);
	printf("\n");
	return 0;
}