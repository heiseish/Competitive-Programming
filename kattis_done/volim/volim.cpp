#include <bits/stdc++.h>
#define BYE 210
using namespace std;
int main() {
	int k, n;
	cin >> k;
	k--;
	cin >> n;
	int t = 0;
	int die = -1;
	bool d = false;
	while(n--) {
		int ti;
		char r;
		cin >> ti >> r;
		t+=ti;
		if (t >= BYE && !d) {
			die = k%8 + 1;
			d = true;
		}
		if (r == 'T') k++;
	}
	cout << die << endl;
	return 0;
}