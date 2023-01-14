#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n;
	cin >> n;
	vector<ii> q;
	for (int i = 0; i < n;i++) {
		ii temp;
		cin >> temp.first >> temp.second;
		q.push_back(temp);
	}
	bool valid = true;
	for (int i = 0; i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (q[i].first == q[j].first || q[i].second == q[j].second 
			|| abs(q[i].first - q[j].first) == abs(q[i].second - q[j].second)) {
				valid = false;
				break;
			}
		}
	}
	if (valid) cout << "CORRECT" << endl;
	else cout << "INCORRECT" << endl;
	return 0;
}