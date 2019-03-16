#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int m = 0, sum =0, index = -1;
		bool winner = false;
		for(int i = 0; i < n;i++) {
			int temp;
			cin >> temp;
			if (temp == m) {
				winner = false;
			} else if (temp > m) {
				winner = true;
				m = temp;
				index = i + 1;
			}
			sum+=temp;
		}
		if (!winner) cout << "no winner" << endl;
		else if (m > sum / 2) cout << "majority winner " << index << endl;
		else cout << "minority winner " << index << endl;
	}
	return 0;
}