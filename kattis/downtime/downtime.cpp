#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	priority_queue<int, vector<int>, greater<int>> sv;
	int svn = 1;
	while(n--) {
		int ts;
		cin >> ts;
		if (sv.size() < svn * k) {
			sv.push(ts);
		} else if (ts - sv.top() >= 1000){
			sv.pop();
			sv.push(ts);
		} else {
			svn++;
			sv.push(ts);
		}

	}
	cout << svn << endl;
	return 0;
}