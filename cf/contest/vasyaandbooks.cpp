#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	// map<int, int> ht;
	int ht[n];
	for (int i = 1; i <= n;i++) {
		int t;
		scanf("%d", &t);
		ht[t - 1] = i;
	}
	int taken = 0;
	for (int i = 1; i <= n;i++) {
		int t;
		scanf("%d", &t);
		if (ht[t - 1] - taken < 0) {
			printf("0 ");
		} else {
			printf("%d ", ht[t - 1] - taken);
			taken = ht[t - 1];
		} 
		
	}
	printf("\n");

	return 0;
}