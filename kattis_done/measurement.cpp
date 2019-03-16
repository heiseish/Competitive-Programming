#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string f, te, t;
	vector<int> m{1, 1000, 12, 3, 22, 10, 8, 3};
	unordered_map<string, int> u;
	u["thou"]  = 0;
	u["inch"] = 1;
	u["foot"] = 2;
	u["yard"] = 3;
	u["chain"] = 4;
	u["furlong"] = 5;
	u["mile"] = 6;
	u["league"] = 7;
	u["th"]  = 0;
	u["in"] = 1;
	u["ft"] = 2;
	u["yd"] = 3;
	u["ch"] = 4;
	u["fur"] = 5;
	u["mi"] = 6;
	u["lea"] = 7;
	cin >> n >> f >> te >> t;
	double r = n;
	int a = u[f];
	if (u[f] <= u[t]) {
		while (a < u[t]) {
			r/=m[a++ + 1];
		}
	} else {
		while (a > u[t]) {
			r*=m[a--];
		}
	}
	printf("%.15f\n", r);

	return 0;
}