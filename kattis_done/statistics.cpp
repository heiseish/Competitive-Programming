#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int count = 1;
	while(scanf("%d", &n) != EOF) {
		vector<int> t;
		int min = 1e6;
		int max = -1e6;
		while(n--) {
			int s;
			cin >> s;
			if (s < min) min = s;
			if (s > max) max = s;
		}
		cout << "Case " << count++ << ": " << min << " " << max << " " << max-min << endl;
	}
	return 0;
}