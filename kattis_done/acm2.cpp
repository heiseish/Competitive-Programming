#include <bits/stdc++.h>

using namespace std;
int main() {
	int N, p;
	cin >> N >> p;
	vector<int> t;
	for (int  i =0; i< N; i++) {
		int temp;
		cin >> temp;
		t.push_back(temp);
	}
	if (t[p] > 300) cout << "0 0" << endl;
	else {
		int m = t[p];
		int count = 1;
		int curr = 0;
		int tl = 300 - t[p];
		t.erase(t.begin() + p);
		sort(t.begin(), t.end());
		while (tl > 0 && curr <= N - 2) {
			if (tl >= t[curr]) {
				count++;
				m+=300-(tl-t[curr]);
			}
			tl -= t[curr++];
		}
		cout << count << " " << m << endl;
	}
	return 0;
}