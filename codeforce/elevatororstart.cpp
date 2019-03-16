#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	if ((abs(y-x) * t1) < (abs(z - x) * t2 + t3 * 3 + abs(y-x) * t2)) {
		cout << "NO" << endl;
	} else cout << "YES" << endl;
	return 0;
}