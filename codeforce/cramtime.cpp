#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll a, b;
	cin >> a >> b;
	ll total = sqrt((a + b) * 2);
	if (total * (total + 1) > (a + b) * 2) total--;
	vector<bool> ln(total, false);
	int larger = max({ a, b});
	int smaller = min({ a, b});
	vector<int> lg;
	vector<int> sm;
	int temp = total;
	while (temp >= 1) {
		if (larger >= temp) {
			ln[temp - 1] = true;
			larger-=temp;
			lg.push_back(temp);
		}
		temp--;
	}
	temp = total;
	while (temp >= 1) {
		if (!ln[temp - 1]) {
			smaller-=temp;
			sm.push_back(temp);
		}
		temp--;
	}
	if (a > b) {
		cout << lg.size() << endl;
		for (auto i : lg) cout << i << " ";
		cout << endl;
		cout << sm.size() << endl;
		for (auto i : sm) cout << i << " ";
		cout << endl;
	} else {
		cout << sm.size() << endl;
		for (auto i : sm) cout << i << " ";
		cout << endl;
		cout << lg.size() << endl;
		for (auto i : lg) cout << i << " ";
		cout << endl;
	}
	return 0;
}