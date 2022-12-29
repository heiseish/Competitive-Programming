#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n), n != -1) {
		int curr=0;
		int t =0;
		while(n--) {
			int s, ti;
			cin >> s >> ti;
			t+= s * (ti - curr);
			curr = ti;
		}
		cout << t << " miles" << endl;
	}
	return 0;
}