#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 1) cout << "ALL GOOD" << endl;
	else if (x!= 0 && y == 1) cout << "IMPOSSIBLE" << endl;
	else {
		double r = -x/ (y - 1.0);
		printf("%.15f\n", r);
	}
	return 0;
}