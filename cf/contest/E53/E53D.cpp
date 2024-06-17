#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

ll b[N];
int main() {
	int n;
	ll t, c = 0;
	scanf("%d %lli", &n, &t);
	for (int i = 0; i < n; i++) scanf("%lli", &b[i]);
	ll mn = *min_element(b, b + n);
	while (t >= mn) {
		ll curT = t;
		ll cnt = 0, orc = 0;
		for (int i= 0; i < n; i++) {
			if (curT >= b[i]) {
				curT -=b[i];
				cnt++;
				orc += b[i];
			}
		}
		c += cnt * (t / orc);
		t%=orc;
	}
	printf("%lli\n", c);
	return 0;
}