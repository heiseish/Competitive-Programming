#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		int nmax = 0, mmax = 0;
		while (n--) {
			int temp;
			cin >> temp;
			if (temp > nmax) nmax = temp;
		}
		while(m--) {
			int temp;
			cin >> temp;
			if (temp > mmax) mmax = temp;
		}
		cout << (nmax >= mmax ? "Godzilla" : "MechaGodzilla") << endl;
		// cin.ignore();
	}
	return 0;
}