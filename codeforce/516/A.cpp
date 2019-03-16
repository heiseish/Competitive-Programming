#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int t = 0;
	int mi = min({a, b, c}), ma = max({ a, b, c});
	if ((a + b + c) - ma  <= ma) t+= 2 * ma -  (a + b + c) + 1;
	cout << t << endl;
	return 0;
}