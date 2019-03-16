#include <bits/stdc++.h>
using namespace std;
vector<string> m;
int n;
vector<vector<vector<string> > > memo;
string curMin = "";
string transverse(string temp, int i, int j) {
	if (i + j == 2 * n + 1) {
		if (temp + m[i][j] < curMin) {
			curMin = temp + m[i][j];
			memo[k][i][j] = string(1, m[i][j]);
		} 
	}
	if (memo[k][i][j] != "") {
		if ((temp + memo[k][i][j] < curMin)) {
			curMin = temp + memo[k][i][j];

		} 
	} else {
		if (i < n - 1 && j < n - 1) {
			
			string t1;
			if (m[i][j] != 'a' && k > 0) t1 = 'a' + transverse(temp + 'a', i + 1, j, k - 1);
			else t1 = m[i][j] + transverse(temp + m[i][j], i + 1, j, k);
			
			string t2;
			if (m[i][j] != 'a' && k > 0) t2 = 'a' + transverse(temp + 'a', i, j + 1, k - 1);
			else t2 = m[i][j] + transverse(temp + m[i][j], i, j + 1, k);

			memo[k][i][j] = min(t1, t2);

		} else if (i < n - 1 ) {
			if (m[i][j] != 'a' && k > 0) memo[k][i][j] = 'a' + transverse(temp + 'a', i + 1, j, k - 1);
			else memo[k][i][j] = m[i][j] + transverse(temp + m[i][j], i + 1, j, k);
		} else if (j < n - 1) {
			if (m[i][j] != 'a' && k > 0) memo[k][i][j] = 'a' + transverse(temp + 'a', i, j + 1, k - 1);
			else memo[k][i][j] = m[i][j] + transverse(temp + m[i][j], i, j + 1, k);
		}
	}
	// cout << "the memo at [" << k << "][" << i << "][" << j << "] is " << memo[k][i][j] << endl; 
	return memo[k][i][j];
}
int main() {
	int k;
	cin >> n >> k;
	vector<string> memos(n, "");
	vector<vector<string> > memos2(n, memos);
	memo.assign(k + 1, memos2);
	for (int i = 0; i < 2 * n + 1;i++) curMin+='z';
	for (int i = 0; i < n;i++) {
		string t;
		cin >> t;
		m.push_back(t);
	}
	transverse("", 0, 0, k);
	cout << curMin << endl;
	return 0;
}