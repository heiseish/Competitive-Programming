#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> c (3, 0);
	cin >> c[0] >> c[1] >> c[2];
	sort(c.begin(), c.end());
	if (c[1] - c[0] < c[2] - c[1]) {
		cout << (c[1] + c[2])/2 << endl;
	} else if (c[1] - c[0] > c[2] - c[1]) {
		cout << (c[1] + c[0])/2 << endl;
	} else {
		cout << 2 * c[2] - c[1] << endl; 
	}
	return 0;
}