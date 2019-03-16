#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <=t;i++){
		printf("Recipe # %d\n",i);
		int r, p, d;
		double sf;
		cin >> r >> p >> d;
		sf = 1.0 * d / p;
		int mi;
		vector<string> names;
		vector<dd> nums;
		for (int j = 0;j< r;j++) {
			string temp;
			double w, per;
			cin >> temp >> w >> per;
			names.push_back(temp);
			nums.push_back({ w, per});
			if (per == 100.0) mi = j;
		}
		nums[mi].first *= sf;
		double nw = nums[mi].first;
		for (auto& i : nums) {
			if (i.first != nw) i.first = (i.second * nw / 100);
		}
		for (int j = 0; j < r;j++) {
			cout << names[j] << " " << fixed << setprecision(1) << nums[j].first << endl;
		}
		for (int i = 0; i < 40;i++) printf("-");
		printf("\n");
	}
	return 0;
}