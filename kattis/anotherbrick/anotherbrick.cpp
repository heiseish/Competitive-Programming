#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, w, n;
	cin >> h >> w >> n;
	bool c = true;
	int cur = w;
	while (n--) {
		int t;
		cin >> t;
		if (t > cur) c = false;
		else if (t == cur) {
			cur = w;
			h--;
		} else {
			cur-=t;
		}
	}
	if (!c) cout << "NO" << endl;
	else if (h <= 0) cout << "YES" << endl;
	return 0;
}