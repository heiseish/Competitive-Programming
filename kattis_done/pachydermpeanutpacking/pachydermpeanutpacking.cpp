#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;
typedef pair<dd, dd> dddd;
int main() {
	int n, m;
	while (cin >> n && n) {
		unordered_map<string, vector<dddd> > b;
		while(n--) {
			double a1, a2, a3, a4;
			string t;
			cin >> a1 >> a2 >> a3 >> a4 >> t;
			b[t].push_back({{a1, a3}, {a2, a4}});
		}
		cin >> m;
		while(m--) {
			double x, y;
			string t;
			cin >> x >> y >> t;
			bool in = false;
			for (auto j : b) {
				for (auto i : j.second) {
					if (x >= i.first.first && x <= i.first.second && y>=i.second.first && y<=i.second.second) {
						in = true;
						if (t == j.first) cout << t << " correct" << endl;
						else cout << t << " " << j.first << endl;
						break; 
					}
				}
			}
				
			if (!in) cout << t << " floor" << endl;
		}
		cout << endl;
	}
	return 0;
}