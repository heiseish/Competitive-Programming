#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--) {
		int d1,m1,y1,d2,m2,y2, c;
		string name;
		cin >> name;
		scanf("%d/%d/%d %d/%d/%d %d", &y1, &m1, &d1, &y2, &m2, &d2, &c);
		if (y1 >= 2010) {
			cout << name << " eligible" << endl; 
		} else if (y2 >= 1991) {
			cout << name << " eligible" << endl;
		} else if (c >= 41) {
			cout << name << " ineligible" << endl;
		} else {
			cout << name << " coach petitions" << endl;
		}
	}
	return 0;
}