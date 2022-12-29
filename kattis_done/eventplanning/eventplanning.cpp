#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, b, h, w;
	cin >> n >> b >> h >> w;
	bool a = false;
	int mon = 0;
	int mi = b + 1;
	while(h--) {
		int ppp; cin >> ppp;
		for(int i = 0; i < w; i++) {
			int av; cin >> av;
			if (av >= n && ppp * n < mi) {
				a = true;
				mon = ppp * n;
				mi = mon;
			}
		}
	}
	if (a) cout << mon << endl;
	else cout << "stay home" << endl;
	return 0;
}