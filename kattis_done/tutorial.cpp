#include <bits/stdc++.h>
#define EPSILON 1E-6
using namespace std;
typedef long long ll;
typedef long double ld;



bool checkFactor(ld m, ll n) {
	if (m < 1) return false;
	if (n == 1) return true;
	m/=n;
	return checkFactor(m, n - 1);
}
int main(){
	ll m, n, t;
	bool s;
	cin >> m >> n >> t;
	switch (t) {
		case 7:
			s = n <= m;
			break;
		case 6:
			s = n * log2(n) <= m;
			break;
		case 5:
			s = n <= pow(m, 0.5) + EPSILON;
			break;
		case 4:
			s = n <= pow(m, 0.333333333333333333) + EPSILON;
			break;
		
		case 3:
			s = n <= pow(m, 0.25) + EPSILON;
			break;

		case 2:
			s = n <= log2(m);
			break;

		case 1:
			s = checkFactor(m * 1.0, n);
			break;

		
	}
	if (s) cout << "AC" << endl;
	else cout << "TLE" << endl;
	return 0;
}