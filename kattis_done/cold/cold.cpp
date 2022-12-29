#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int c = 0;
	while(n--) {
		int t;cin >>t;
		if (t<0)c++;
	}
	cout << c << endl;
	return 0;
}