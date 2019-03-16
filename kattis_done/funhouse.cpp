#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<string> h;

ii move(ii start, char dir) {
	switch (dir) {
		case 'D':
		return {start.first + 1, start.second};
		case 'U':
		return {start.first-1, start.second};
		case 'R':
		return {start.first, start.second+1};
		default:
		return {start.first, start.second-1};
	}
}

char changeDir(char dir, char mir) {
	if (mir == '\\') {
		if (dir == 'R') return 'D';
		else if (dir == 'U') return 'L';
		else if (dir == 'D') return 'R';
		else return 'U';
	} else {
		if (dir == 'R') return 'U';
		else if (dir == 'U') return 'R';
		else if (dir == 'D') return 'L';
		else return 'D';
	}
}
int main() {
	int w, l;
	int cn = 1;
	while(cin >> w >> l && (w || l)) {
		h.clear();
		for (int i = 0;i<l;i++) {
			string t;
			cin >> t;
			h.push_back(t);
		}
		ii entry;
		char dir;
		for (int i =0;i<l;i++) {
			for (int j = 0; j < w;j++) {
				if (h[i][j] == '*') {
					entry.first = i;
					entry.second=j;
					if (i == 0) dir = 'D';
					else if (i==l-1) dir='U';
					else if (j==0) dir='R';
					else dir='L';
				}
			}
		}
		entry = move(entry, dir);
		while(h[entry.first][entry.second] != 'x') {
			if (h[entry.first][entry.second] == '\\'
			|| h[entry.first][entry.second] == '/') {
				dir = changeDir(dir, h[entry.first][entry.second]);	
			} 
			entry = move(entry, dir);
		}
		h[entry.first][entry.second] = '&';
		cout << "HOUSE " << cn++ << endl;
		for (auto i : h) cout << i << endl;

	}
	return 0;
}