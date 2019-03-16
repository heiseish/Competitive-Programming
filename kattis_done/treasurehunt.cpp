#include <bits/stdc++.h>
using namespace std;
bool isOut(int x, int y, int w, int l) {
	return x < 0 || x >= w || y < 0 || y >= l;
}

int main() {
	int r, c;
	cin >> r >> c;
	vector<string> m(r, "");
	for (int i = 0; i < r ; i++) {
		cin >> m[i];
	}
	vector<vector<bool> > e(r, vector<bool> (c, false));
	int pr = 0, pc = 0;
	int cnt = 0;
	bool found = true;
	while (!isOut(pc, pr, c, r) && m[pr][pc] != 'T') {
		// cout << cnt << endl;
		cnt++;
		if (e[pr][pc]) {
			found = false;
			break;
		}
		e[pr][pc] = true;
		if (m[pr][pc] == 'N') pr--;
		else if (m[pr][pc] == 'E') pc++;
		else if (m[pr][pc] == 'W') pc--;
		else pr++;
		
	}
	if (!found) cout << "Lost" << endl;
	else if (isOut(pr, pc, r, c)) cout << "Out" << endl;
	else cout << cnt << endl;
	return 0;
}