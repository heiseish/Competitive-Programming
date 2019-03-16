#include <bits/stdc++.h>
using namespace std;
int main() {
	string m;
	int d, y;
	while (cin >> m >> d >> y && !cin.eof()) {
		int srh, srm, ssh, ssm;
		scanf("%d:%d %d:%d", &srh, &srm, &ssh, &ssm);
		if (srm > ssm) {
			ssh--;
			ssm+=60;
		}
		cout << m << " " << d << " " << y << " " 
		<< ssh - srh << " hours " << ssm - srm << " minutes" << endl;
	}
	return 0;
}