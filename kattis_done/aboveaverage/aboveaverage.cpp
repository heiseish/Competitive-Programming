#include <bits/stdc++.h>

using namespace std;
int main() {
	int c;
	cin >> c;
	while(c-- > 0) {
		int n;
		double sum = 0.0;
		cin >> n;
		vector<int> s;
		for (int i =0; i<n;i++) {
			int temp; 
			cin >> temp;
			s.push_back(temp);
			sum += temp;
		}
		sum/=n;
		double count = 0.00;
		for (auto i : s) {
			if (i > sum) {
				count+=1.0;
			}
		}
		cout << setprecision(3) << fixed<< count/n * 100 << "%" << endl;
	}
	return 0;
}