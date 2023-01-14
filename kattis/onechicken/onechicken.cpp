#include <iostream>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	if (m > n) {
		cout << "Dr. Chaz will have " << m-n << " piece" << (m-n>1 ? "s" : "") << " of chicken left over!" << endl;
	} else {
		cout << "Dr. Chaz needs " << n-m << " more piece" << (n-m>1 ? "s" : "") <<  " of chicken!" << endl;
	}
	return 0;
}