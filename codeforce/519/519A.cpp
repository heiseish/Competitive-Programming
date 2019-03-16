#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0;
	vector<int> v(n);
	int l = 0;
	for (int i = 0 ; i < n; i++) {
		scanf("%d", &v[i]);
		sum+=v[i];
		l = max(l, v[i]);
	}
	sum*=2;
	sum++;
	if (sum <= l * n) {
		cout << l << endl;
	} else
		cout << ceil(1.0 * sum/n) << endl;
	return 0;
}