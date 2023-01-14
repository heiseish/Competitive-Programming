#include <bits/stdc++.h>
using namespace std;
int main() {
	string t;
	cin >> t;
	int curr = 1;
	for (auto ch : t) {
		if (ch == 'A' && curr < 3) curr=3-curr;
		if (ch == 'B' && curr > 1) curr=5-curr;
		if (ch == 'C' && curr !=2) curr=4-curr; 
	}
	cout << curr << endl;
	return 0;
}