#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int d;
		scanf("%d", &d);
		if (d*d - 4*d < 0) {
			printf("N\n");
			continue;
		} else {
			double a = (d - sqrt(d * d - 4 *d))/2;
			double b = d - a;
			printf("Y %.10f %.10f\n", a, b);
		}
	}
	return 0;
}