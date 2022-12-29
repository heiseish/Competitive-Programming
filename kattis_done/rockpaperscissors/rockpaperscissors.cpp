#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n;
	while(scanf("%d", &n),n) {
		vector<ii> s(n, {0, 0});
		int k;
		cin >> k;
		int g = k * n * (n - 1) / 2;
		while (g--) {
			int p1, p2;
			string h1, h2;
			cin >> p1 >> h1 >> p2 >> h2;
			if (h1 != h2) {
				if (h1 == "paper") {
					if (h2 == "scissors") {
						s[p1 - 1].second++;
						s[p2 - 1].first++;
					} else if (h2 == "rock") {
						s[p1 - 1].first++;
						s[p2 - 1].second++;
					}
				} else if (h1 == "rock") {
					if (h2 == "scissors") {
						s[p1 - 1].first++;
						s[p2 - 1].second++;
					} else if (h2 == "paper") {
						s[p1 - 1].second++;
						s[p2 - 1].first++;
					}
				} else {
					if (h2 == "rock") {
						s[p1 - 1].second++;
						s[p2 - 1].first++;
					} else if (h2 == "paper") {
						s[p1 - 1].first++;
						s[p2 - 1].second++;
					}
				}
			}
		} 
		for (auto i : s) {
			double res = 1.0 * i.first / (i.first + i.second);
			if (isnan(res)) printf("-\n");
			else printf("%.3f\n", res);
		}
		printf("\n");
	}
	return 0;
}