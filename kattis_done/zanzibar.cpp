#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		int curr = -1;
		int i = 0;
		while(scanf("%d", &n), n) {
			if (curr != -1) i += max({ n - curr * 2, 0});
			curr = n;
		}
		cout << i << endl;
	}
	return 0;
}