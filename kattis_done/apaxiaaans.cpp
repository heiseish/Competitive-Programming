#include <bits/stdc++.h>
using namespace std;
int main() {
	string temp;
	cin >> temp;
	for (int i = 0; i < temp.length(); i++) {
		if (i != temp.length() - 1 && temp[i] == temp[i+1]) continue;
		cout << temp[i];
	}
	cout << endl;
	return 0;
}