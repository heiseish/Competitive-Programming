#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		char fb;
		int d, h, m;
		cin >> fb >> d >> h >> m;
		if (fb == 'F') {
			m+=d;
			h+=m/60;
			m%=60;
		} else {
			while (m < d) {
				m+=60;
				h--;
			}
			m-=d;
		}
		if (h < 0) h+=24;
		else if (h >= 24) h-=24;
		cout << h << " " << m << endl;
	}
	return 0;
}