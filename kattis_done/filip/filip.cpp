#include <iostream>
using namespace std;
int reverse(int n) {
	int res = 0;
	while (n) {
		res = 10 * res + n%10;
		n/=10;
	}
	return res;
}
int main() {
	int a, b;
	cin >> a >> b;
	cout << (reverse(a) > reverse(b) ? reverse(a) :  reverse(b)) << endl;
	return 0;
}