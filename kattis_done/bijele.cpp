#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> d {1, 1, 2, 2, 2, 8};
	for (int i = 0; i < 6; i++) {
		int t;
		cin >> t;
		if (i == 5) cout << d[i] - t << endl;
		else cout << d[i] - t << " ";
	}
	return 0;
}