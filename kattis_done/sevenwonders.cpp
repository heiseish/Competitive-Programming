#include <bits/stdc++.h>
using namespace std;
int main() {
	string t;
	cin >> t;
	vector<int> s(3, 0);
	for (auto c : t) {
		if (c == 'T') s[0]++;
		if (c == 'C') s[1]++;
		if (c == 'G') s[2]++;
	}
	cout << s[0] * s[0] + s[1] * s[1] + s[2] * s[2] + 7 * min({s[0], s[1], s[2]}) << endl;
	return 0;
}