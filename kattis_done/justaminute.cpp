#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	int w = 0, d = 0;
	while(t--) {
		int m, s;
		cin >> m >> s;
		d+=m;
		w+=s;
	}
	double r = w/ (d * 60.0);
	if (r > 1) printf("%.15f\n", r);
	else cout << "measurement error" << endl;
	return 0;
}