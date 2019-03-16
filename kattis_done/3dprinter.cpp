#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > d;

int recurse(int printer, int statue) {
	if (printer >= statue) return 1;
	if (d[printer][statue] == -1) d[printer][statue] = min({recurse(printer * 2, statue), recurse(printer, statue - printer)});
	return 1 + d[printer][statue];
}
int main() {
	int n;
	cin >> n;
	d = vector<vector<int> > (n + 1, vector<int>(n + 1, -1));
	cout << recurse(1, n) << endl;
	return 0;
}