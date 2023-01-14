#include <bits/stdc++.h>
using namespace std;
int main() {
	int r, n;
	cin >> r >> n;
	vector<int> h(r, 1);
	int m =n;
	while(m--) {
		int t;
		cin >> t;
		h[t-1] = 0;
	}
	if (n == r) cout << "too late" << endl;
	else {
		for (int i = 1; i <= r; i++) {
			if (h[i-1]) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}