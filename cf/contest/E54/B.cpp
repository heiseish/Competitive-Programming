#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is(ll n) {
	if (n%2==0) return false;
	for (ll i = 3; i * i <= n;i+=2) {
		if (n%i==0) return false;
	}
	return true;
}

int main() {
	ll n;
	cin >> n;
	if (is(n)) printf("1\n");
	else if (n%2==0) printf("%lld\n", n/2);
	else {
		for (int i = 2; i <= n; i++) {
			if (is(i) && n%i == 0) {
				printf("%lld\n", (n-i)/2 + 1 );
				break;
			}
		}
	}
	return 0;
}