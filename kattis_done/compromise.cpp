#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<string> o;
		for (int i =0;i<n;i++) {
			string te;
			cin >> te;
			o.push_back(te);
		}
		string res = "";
		for (int i = 0;i<m;i++) {
			int cn = 0;
			for (int j = 0; j<n;j++) {
				// cout << o[i][j] << endl;
				cn+=(o[j][i]-'0');
			}
			// cout << "for i = " << i << " cn is " << cn << endl;
			if (cn * 2 >= n) res+='1';
			else res+='0';
		}
		cout << res << endl;
	}
	return 0;
}