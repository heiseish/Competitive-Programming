#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	int c = 0;
	int num = 0;
	while(n--) {
		int temp;
		cin >> temp;
		c+=temp;
		if (c <= t) num++;
	}
	cout << num << endl;
	return 0;
}