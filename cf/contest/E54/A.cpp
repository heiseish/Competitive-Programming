#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int main() {
	long long n;
	char s[maxn];
	scanf("%lld", &n);
	char MAX = 'a';
	scanf("%s", s);
	int idx;
	for (int i = 0; i < n; i++) {
		if (i==n-1) idx = i;
		else if (s[i] > s[i+1]) {
			idx = i;
			break;
		}
	}
	bool alr = false;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}