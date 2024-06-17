#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool d = true;
	string r = "";
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != s[i+1]) {
			d = false;
			r += s[i];
			r += s[i+1];
			break;
		}
	}
	if (d) cout << "NO" << endl;
	else {
		cout << "YES" << endl << r << endl;
	}
	return 0;
}