#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> b;
	while(n--) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	sort(b.begin(), b.end());
	int count = 0, begin = -1, end = -1;
	for (int i = 0; i < b.size();i++) {
		if (count == 0) {
			count++;
			begin = b[i];
			end = b[i];
		} else if (b[i] != b[i-1] + 1) {
			if (count == 1) {
				cout << begin << " ";
			} else if (count == 2) {
				cout << begin << " " << end << " ";
			} else {
				cout << begin << "-" << end << " ";
			}
			count = 1;
			begin = end = b[i];
		} else {
			count++;
			end = b[i];
		}
	}
	if (count == 1) {
		cout << begin << endl;
	} else if (count == 2) {
		cout << begin << " " << end << endl;
	} else {
		cout << begin << "-" << end << endl;
	}
	return 0;
}