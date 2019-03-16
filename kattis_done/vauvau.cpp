#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int t = 3;
	while(t--) {
		int bite = 0;
		int p;cin>>p;
		if (0 <p%(a+b) && p%(a+b) <= a) bite++;
		if (0 < p%(c+d) && p%(c+d) <= c) bite++;
		cout << ((bite == 0) ? "none" : ((bite==1) ? "one" : "both")) << endl;
	}

	return 0;
}