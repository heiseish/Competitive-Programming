#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int m, d;
		cin >> d >> m;
		int f = 0, c = 0;
		while(m--) {
			int temp;
			cin >> temp;
			if (temp >= 13 && (c+13)%7==6) f++;
			c+= temp;
		}
		cout << f << endl;
	}
	return 0;
}