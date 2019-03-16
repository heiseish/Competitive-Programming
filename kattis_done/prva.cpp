#include <bits/stdc++.h>
using namespace std;
vector<string> p;
int r, c;
string getHor(int i, int j) {
	string res = "";
	while(j < c && p[i][j] != '#') {
		res+=p[i][j++];
		
	}
	return res;
}
string getVer(int i, int j) {
	string res= "";
	while(i < r && p[i][j] != '#') {
		res+=p[i++][j];
	}
	return res;
}
int main() {
	cin >> r >> c;
	for (int i = 0;i<r;i++) {
		string t;
		cin >> t;
		p.push_back(t);
	}
	vector<string> d;
	for (int i = 0; i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (p[i][j]!='#') {
				if (j == 0 || (j > 0 && p[i][j-1] == '#')) {
					string t1 = getHor(i, j);
					if (t1.length() >=2) d.push_back(t1);
				}
				if (i == 0 || (i > 0 && p[i-1][j] == '#')) {
					string t2 = getVer(i , j);
					if (t2.length() >=2) d.push_back(t2);
				}
			}
			
		}
	}
	sort(d.begin(), d.end());
	cout << d[0] << endl;
	return 0;
}