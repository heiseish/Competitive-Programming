#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;


void add(int& a, int b) {
	a+=b;
	if (a >= MOD) a -= MOD;
}

int sum (int a, int b) {
	add(a, b);
	return a;
}

int multiply(int a, int b) {
	return (long long) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = multiply(ret, a);
		}
		a = multiply(a, a);
		b >>= 1;
	}
	return ret;
}
int main() {
	int n, q;
	char d[maxn];
	int num[maxn];
	int tot[maxn] = { 0 };
	scanf("%d %d", &n, &q);
	scanf("%s", d);
	for (int i = 1; i <= n; i++) {
		num[i] = d[i - 1] - '0';
		tot[i] = tot[i - 1] + num[i];
	}
	while(q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int MAX = 0;
		int curd = r - l;
		int is1 = tot[r] - tot[l-1];
		long res = multiply(mpow(2, r - l - is1 + 1), sum(mpow(2, is1), MOD - 1));
		printf("%ld\n", res);
	}
	return 0;
}