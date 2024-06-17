#include <bits/stdc++.h>
using namespace std;
const int maxn = 10e3 + 10;
int num[maxn];
int main() {
	int n;
	scanf("%d", &n);
	int MAX = 0, cur = -1, cons = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] == cur + 1) {
			if (num[i] == 1e3 || cur == 1) cons++;
			cons++;
		} else {
			cons = 1;
		}
		cur = num[i];
		if (cons - 2 > MAX) MAX = cons - 2;
	}
	printf("%d\n", MAX);
	return 0;
}