#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	vector<int> st, en;
	cin >> a >> b >> c;
	for (int i =0;i<3;i++) {
		int s, e;
		cin >> s >> e;
		st.push_back(s);
		en.push_back(e);
	}
	int k = 0;
	vector<int> sum{0, 0, 0, 0};
	for (int i = 1; i <= 100; i++) {
		k+=count(st.begin(), st.end(), i);
		k-=count(en.begin(), en.end(), i);
		sum[k]++;
	}
	cout << sum[1] * a + sum[2] * b * 2 + sum[3] * c * 3 << endl;
	return 0;
}