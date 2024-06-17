#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		int t;
		scanf("%d", &t);
		int k = __builtin_popcount(t);
		k = pow(2, k);
		printf("%d\n", k);
	}
	return 0;
}