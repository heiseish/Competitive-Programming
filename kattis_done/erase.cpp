#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	bool e = true;;
	if (n%2==0) {
		e = s1 == s2;
	} else {
		for (int i = 0; i < s1.length();i++) {
			if (s1[i] + s2[i] != '1' + '0')  {
				e = false;
				break;
			}
		}
	}
	if (e) cout << "Deletion succeeded" << endl;
	else cout << "Deletion failed" << endl;
	return 0;
}