#include <bits/stdc++.h>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		int n, l;
		cin >> l >> n;
		int mi = 0, ma;
		int s1 = 0, s2 = l;
		while(n--) {
			int temp;
			cin >> temp;
			mi = max({ mi, temp > l / 2 ? l - temp : temp });
			s1 = temp > s1 ? temp : s1;
			s2 = temp < s2 ? temp : s2;
		}
		ma = l - s1 >= s2 ?  l - s2 : s1;
		cout << mi << " " << ma << endl;
	}
	return 0;
}