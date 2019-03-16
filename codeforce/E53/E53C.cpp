#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
string s;
int x, y, n;

void move(char d, int& x0, int& y0, int step) {
	if (d == 'U') y0+=step;
	if (d == 'D') y0-=step;
	if (d == 'L') x0-=step;
	if (d == 'R') x0+=step;
}
bool can(int x, int y, int n) {
	x = abs(x);
	y = abs(y);
	return ((x + y)%2 == n % 2) && (x + y <= n);
}

bool check(int m) {
	int x0 = 0, y0 = 0;
	for (int i = m; i < n; i++) {
		move(s[i], x0, y0, 1);
	}
	int l = 0, r = m;
	while(true) {
		if (can(x - x0, y - y0, m)) return true;
		if (r == n) break;
		move(s[l++], x0, y0, 1);
		move(s[r++], x0, y0, -1);
	}
	return false;
}

int main() {
	cin >> n >> s >> x >> y;
	int l = -1, r = n;
	if (!can(x, y, n)) {
		cout << -1 << endl;
		return 0;
	}
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << r << endl;
	return 0;
}