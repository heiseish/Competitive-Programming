#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n+1, 0);
	vector<int> s;
	for(int i = 1; i <= n;i++) {
		scanf("%d", &a[i]);
	}
	vector<int> t;
	for(int i = 1; i <= n;i++) {
		t.assign(i, 0);
		int k = 0;
		for (;k < i;k++) {
			t[k] = a[k + 1] - a[k]; 
		}
		bool can = true;
		while(k <= n - 1) {
			if (t[k%i] != a[k + 1] - a[k]) {
				// cout << "k is " << k << endl;
				// cout << "k mod i is " << k%i << endl;
				// cout << "t[k%i] is " << t[k%i] << endl;
				// cout <<"rhs is " << a[k + 1] - a[k] << endl;
				can = false;
				break;
			}
			k++;
		}
		if (can) {
			s.push_back(i);
		}
	}
	cout << s.size() << endl;
	for (auto i : s) cout << i << " ";
	cout << endl;
	return 0;
}