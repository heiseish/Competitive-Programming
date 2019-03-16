#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, m;
	cin >> h >> m;
	if (m < 45) {
		h--;
		m+=60;
	}
	if (h < 0) h+=24;
	m-=45;
	cout << h << " " << m << endl;
	return 0;
}