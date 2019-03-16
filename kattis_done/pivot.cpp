#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> r;
	for (int i =0; i < n; i++){
		int temp;
		cin >> temp;
		r.push_back(temp);
	}
	vector<int> s(r);
	sort(s.begin(), s.end());
	int count = 0;
	int max = s[0];
	for (int i =0; i<n;i++) {
		if (s[i] == r[i] && max <= r[i]) count++;
		if (r[i] > max) max = r[i];
	}
	cout << count << endl;
	return 0;
}