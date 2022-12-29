#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > m;
int n;
string t = "ICPCASIASG";
bool found = false;
vector<pair<int, int> > getPossibleJump(int i, int j) {
	vector<pair<int, int> > r;
	int lh = i >= 2 ? i - 2 : 0;
	int hh = i <= n - 3 ? i + 2 : n - 1;
	int lv = j >= 2 ? j - 2 : 0;
	int hv = j <= n - 3 ? j + 2 : n - 1;
	for (int ii = lh; ii <= hh; ii++) {
		for (int jj = lv; jj <= hv; jj++ ) {
			if (pow(i - ii, 2) + pow(j - jj, 2) == 5) r.push_back({ ii, jj });
		}
	}
	return r;
}
void explore(int i, int j, int in) {
	if (in == 10) found = true;
	if (found) return;
	for (auto p : getPossibleJump( i, j)) {
		if (m[p.first][p.second] == t[in]) explore(p.first, p.second, in + 1);
	}
}

int main() {
	string S;
	cin >> n >> S;
	m.assign(n, vector<char>(n, 'X'));
	int c = 0;
	for (int i =0; i < n; i++) {
		for (int j =0; j <n; j++) {
			m[i][j] = S[c++];
		}
	}
	for (int i =0; i < n; i++) {
		for (int j =0; j <n; j++) {
			if (m[i][j] == t[0]) explore(i, j, 1);
		}
	}
	if (found) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}