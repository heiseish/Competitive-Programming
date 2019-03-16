#include <bits/stdc++.h>

using namespace std;

int main() {
	int l, a, b, t, r, n;
	vector<int> checkpoints;
	cin >> l >> a >> b >> t >> r >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		checkpoints.push_back(temp);
	}

	vector<int> res;
	int coffeeTimeLeft = 0;
	int waitingTimeLeft = 0;
	for (int i = 0; i < n - 1; i++) {
		int notTaking = checkpoints[i + 1] - checkpoints[i] < coffeeTimeLeft * b  ? 
			(checkpoints[i + 1] - checkpoints[i]) / b :
			(checkpoints[i + 1] - checkpoints[i] - coffeeTimeLeft * b ) / a < t ?
			coffeeTimeLeft + (checkpoints[i + 1] - checkpoints[i] - coffeeTimeLeft * b ) / a :
			coffeeTimeLeft + t + (checkpoints[i + 1] - checkpoints[i] - coffeeTimeLeft * b - t * a) / b; 
		int taking = (checkpoints[i + 1] - checkpoints[i]) / a < t ?
			(checkpoints[i + 1] - checkpoints[i]) / a :
			t + coffeeTimeLeft + t + (checkpoints[i + 1] - a * t) / b;

		if (taking >= notTaking) {
			res.push_back(i);

		}
	}
	return 0;
}