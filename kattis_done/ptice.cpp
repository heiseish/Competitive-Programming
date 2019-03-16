#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string adrian = "ABC";
	string bruno = "BABC";
	string goran = "CCAABB";
	int  a = 0, b = 0, g = 0;
	string temp;
	cin >> temp;
	for (int i = 0; i < n;i++) {
		char t = temp[i];
		if (t == adrian[i % adrian.length()]) a++;
		if (t == bruno[i % bruno.length()]) b++;
		if (t == goran[i % goran.length()]) g++;
	}
	int m = max({a, b, g});
	cout << m << endl;
	if (a == m) cout << "Adrian" << endl;
	if (b == m) cout << "Bruno" << endl;
	if (g == m) cout << "Goran" << endl;
	return 0;
}