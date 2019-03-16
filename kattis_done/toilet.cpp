#include <bits/stdc++.h>
using namespace std;
int main() {
	string m;
	cin >> m;
	char pos = m[0];
	m.erase(0, 1);
	int a1 = 0, a2 = 0, a3 = 0;
	char cur = pos;
	for (auto i : m) {
		if (cur == 'D') a1++;
		else if (i == 'D') a1+=2;
		cur = 'U';
	}
	cur = pos;
	for (auto i : m) {
		if (cur == 'U') a2++;
		else if (i == 'U') a2+=2;
		cur = 'D';
	}
	cur = pos;
	for (auto i : m) {
		if (i != cur) a3++;
		cur = i;
	}
	cout << a1 << endl << a2 << endl << a3 << endl;
	return 0;
}