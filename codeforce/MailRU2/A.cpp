#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	bool can = false;
	vector<int> stf(n);
	vector<int> stb(n);
	for (int i = 0; i < n; i++) scanf("%d", &stf[i]);
	for (int i = 0; i < n; i++) scanf("%d", &stb[i]);
	if (stf[0] == 0) {
		printf("NO\n");
		return 0;
	}
	if (stf[s-1] == 1) {
		printf("YES\n");
		return 0;
	}
	if (stb[s-1] == 0) {
		printf("NO\n");
		return 0;
	}
	for (int i = s - 1; i < n; i++) {
		if (stf[i] && stb[i]) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}