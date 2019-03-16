#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, x, y;
	cin >> n >> x >> y;
	ll distW = max(x - 1, y - 1);
	ll distB = max(n - x, n - y);
	if (distW <= distB) {
		cout << "White" << endl;
	} else cout << "Black" << endl;
	return 0;
}