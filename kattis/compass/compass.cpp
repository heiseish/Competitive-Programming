#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	if (n > m) {
		if (n - m < m + 360 - n) cout << -(n - m) << endl;
		else cout << m + 360 - n << endl;
	} else {
		if (m - n <= n + 360 - m) cout << m - n << endl;
		else cout << -(n + 360 - m) << endl;
	}
	return 0;
}