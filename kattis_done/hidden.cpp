#include <bits/stdc++.h>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	unordered_set<char> r;
	int i = 0;
	bool l = true;
	for (auto ch : s2) {
		if (i == s1.length()) break;
		if (ch == s1[i] && r.find(ch) == r.end()) {
			i++;
		} else if (ch == s1[i] && r.find(ch) != r.end()) {
			l=false;
			break;
		} else r.insert(ch);
	}
	if (!l || i < s1.length()) cout << "FAIL" << endl;
	else cout << "PASS" << endl;
	return 0;
}