#include <bits/stdc++.h>
using namespace std;

bool compare(const string& lhs, const string& rhs) {
	for (int i = 0;i<lhs.length();i++) {
		if (tolower(lhs[i]) == tolower(rhs[i])) continue;
		return tolower(lhs[i]) < tolower(rhs[i]);
	}
	return false;
}
int main() {
	int r, c;
	while (cin >> r >> c && (r || c)) {
		vector<string> a, b;
		for (int i =0;i<r;i++) {
			string temp;
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < c;i++) {
			string d = "";
			for (int j = 0; j < r;j++) {
				d+=a[j][i];
			}
			b.push_back(d);
		}
		stable_sort(b.begin(), b.end(), compare);
		a.clear();
		for (int i = 0; i < r;i++) {
			string d = "";
			for (int j = 0; j < c;j++) {
				d+=b[j][i];
			}
			a.push_back(d);
		}
		for (auto i : a) cout << i << endl;
		cout << endl;

	}
	return 0;
}