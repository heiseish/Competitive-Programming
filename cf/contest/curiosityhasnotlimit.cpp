#include <bits/stdc++.h>
using namespace std;
vector<int> a,b;
bool can = false;
vector<int> res;
bool permutate(int index, int curr) {
	if (index == a.size()) {
		can = true;
		res.push_back(curr);
		return true;
	}
	for (int i = 0; i < 4; i ++) {
		if ((curr | i) == a[index] && (curr & i) == b[index]) {
			if (permutate(index + 1, i)) {
				res.push_back(curr);
				return true;
			}
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n - 1;i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n - 1;i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	for (int i = 0; i < 4; i ++) {
		if (permutate(0, i)) {
			break;
		}
	}

	if (!can) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		reverse(res.begin(), res.end());
		for (auto i : res) cout << i << " ";
		cout << endl;
	}
	return 0;
}