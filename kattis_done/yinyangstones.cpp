#include <bits/stdc++.h>
using namespace std;
int main() {
	string t;
	cin >> t;
	int b=0,w=0;
	for (auto c : t) {
		if (c == 'B') b++;
		else w++;
	}
	cout << (b == w ? 1 : 0) << endl;
	return 0;
}