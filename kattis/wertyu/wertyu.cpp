#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> k(4, "");
	k[0] = "`1234567890-=";
	k[1] = "QWERTYUIOP[]\\";
	k[2] = "ASDFGHJKL;'";
	k[3] = "ZXCVBNM,./";
	unordered_map<char, char> nk;
	for (auto i : k) {
		for (int j = 1; j < i.length(); j++) {
			nk[i[j]] = i[j-1];
		}
	}
	nk[' '] = ' ';
	string temp;
	while (getline(cin, temp)) {
		for (auto i : temp) cout << nk[i];
		cout << endl;
	}
	return 0;
}