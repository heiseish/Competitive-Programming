#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<bool> d(52, false);
	string temp;
	cin >> temp;
	int cur = 0;
	vector<int> c(4, 13);
	bool error = false;
	while(cur < temp.length()) {
		int val = 0;
		int de = -1;
		switch(temp[cur]) {
			case 'P':
			de = 0;
			break;
			case 'K':
			de = 1;
			break;
			case 'H':
			de = 2;
			break;
			default:
			de = 3;
		}
		val = de * 13 + (temp[cur+1] - '0') * 10 + (temp[cur+2] - '0');
		if (d[val]) {
			error=true;
			break;
		}
		d[val] = true;
		c[de]--;
		cur+=3;
	}
	if (error) cout << "GRESKA" << endl;
	else cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
	return 0;
}