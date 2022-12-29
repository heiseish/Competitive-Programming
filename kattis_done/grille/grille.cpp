#include <bits/stdc++.h>
#define loopI for (int i=0;i<n;i++)
#define loopJ for (int j=0;j<n;j++)
using namespace std;
typedef vector<char> v;
typedef vector<v> vv;

vv rotate(vv m) {
	vv temp = m;
	int n = m.size();
	loopI {
		loopJ {
			temp[i][j] = m[n - 1 - j][i];
		}
	}
	return temp;
}
int main() {
	int n;
	cin >> n;
	vv m(n, v(n, '.')); 
	vv r(n, v(n, '.'));
	loopI {
		loopJ {
			cin >> m[i][j];
		}
	}

	string temp;
	cin >> temp;
	int current = 0;
	bool nice = true;
	int times = 4;
	while(times-- > 0) {
		loopI {
			loopJ {
				if (m[i][j] == '.') {
					if (current >= n * n) {
						nice = false;
						break;
					} else r[i][j] = temp[current++];
				}
			}
		}
		m = rotate(m);
	}
	if (!nice) {
		cout << "invalid grille" << endl;
		return 0;
	}
	string tmp = "";
	
	loopI {
		loopJ {
			if (r[i][j] == '.') {
				nice = false;
				break;
			} else tmp += r[i][j];
		}
	}
	if (!nice) cout << "invalid grille" << endl;
	else cout << tmp << endl;
	return 0;
}