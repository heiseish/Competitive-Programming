#include <bits/stdc++.h>
using namespace std;
int main() {
	int M, P, L;
	int E, R, S, N;
	while(scanf("%d", &M) != EOF) {
		cin >> P >> L;
		cin >> E >> R >> S >> N;
		vector<int> c(3, 0);
		c[0] = L;
		c[1] = P;
		c[2] = M;
		while(N--) {
			vector<int> temp = c;
			temp[0] = c[2] * E;
			temp[1] = c[0] / R;
			temp[2] = c[1] / S;
			c = temp;
		}
		cout << c[2] << endl;
	}
	
	return 0;
}