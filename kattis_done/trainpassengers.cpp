#include <bits/stdc++.h>
using namespace std;
int main() {
	int c, n;
	cin >> c >> n;
	int pass = 0;
	bool can = true;
	while(n--) {
		int l, e, w;
		cin >> l >> e >> w;
		pass-=l;
		if (pass < 0) can = false;
		pass+=e;
		if (pass > c) can = false;
		if (pass < c && w > 0) can = false;
	}
	if (pass != 0) can = false;
	if (!can) cout << "impossible" << endl;
	else cout << "possible" << endl;
	return 0;
}