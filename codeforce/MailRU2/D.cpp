#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vi;

const int maxn = 3005;
string temp;
string dif = "", tr = "";

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
	int n;
	scanf("%d", &n);
	vi o(n), t(n);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		o[i] = temp;
	}
	bool can = true;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		t[i] = temp;
		if (!can) continue;
		
		if (o[i] != t[i] && dif == "") {
			dif = o[i];
			tr = t[i];
		} else if (o[i] != t[i]) {
			string tmps = "", tmpt = "";
			int start = -1, end = -1;
			for (int j = 0; j < o[i].length(); j++) {
				if (o[i][j] != t[i][j]) {
					start = j;
					break;
				}
			}
			for (int j = o[i].length() - 1; j >= 0; j--) {
				if (o[i][j] != t[i][j]) {
					end = j;
					break;
				}
			}


			tmps = o[i].substr(start, end - start + 1);
			tmpt = t[i].substr(start, end - start + 1);
			if (tmps.length() > dif.length()) {
				can = false;
				continue;
			}

			if (dif.find(tmps) == string::npos || tr.find(tmpt) == string::npos) {
				can = false;
				continue;
			}
			int curs = start - 1, cure = end + 1;
			// expand
			while(curs >= 0 && dif.find(o[i][curs] + tmps) != string::npos) {
				tmps = o[i][curs] + tmps;
				tmpt = t[i][curs] + tmpt;
				curs--;
			}

			while(cure < o[i].length() && dif.find(tmps + o[i][cure]) != string::npos) {
				tmps += o[i][cure];
				tmpt += t[i][cure];
				cure++;
			}
			dif = tmps;
			tr = tmpt;
		}
	}
	if (!can) cout << "NO" << endl;
	else {
		for (int i = 0; i < n; i++) if (o[i].find(dif) != string::npos && o[i].replace(o[i].find(dif), dif.length(), tr) != t[i]) can = false;
		if (!can) cout << "NO" << endl;
		else cout << "YES\n" << dif << endl <<  tr << endl;
	}
	return 0;
}