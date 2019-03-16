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
	if (is(n)) cout << 1 << endl;
	else {
		int ct = 0;
		while (n%2==0) {
			ct++;
			n/=2;
		}
		for (ll k = 3;k*k<=n;k+=2) {
			while (n%k==0) {
				ct++;
				n/=k;
			}
		}
		if (n > 1) ct++;
		cout << ct << endl;
	}
	return 0;
}