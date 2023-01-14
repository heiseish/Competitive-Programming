#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<char, int> ci;
set<ii> getNeighbor(ii cor) {
	int x = cor.first, y = cor.second;
	set<ii> r;
	while (--x>=0 && ++y < 8) r.insert({x, y});
	x = cor.first, y = cor.second;
	while(++x<8 && --y>=0) r.insert({x, y});
	x = cor.first, y = cor.second;
	while(--x>=0 && --y>=0) r.insert({x, y});
	x = cor.first, y = cor.second;
	while(++x<8 && --y>=0) r.insert({x, y});
	x = cor.first, y = cor.second;
	while(++x<8&++y<8) r.insert({x, y});
	return r;
}

ii toCordinate(char x, int y) {
	return { x - 'A', y - 1};
}

ci toReadable(int x, int y) {
	return { 'A' + x, y + 1};
}

int main() {
	int t;
	cin >> t;
	vector<string> m(8, "");
	m[0] = m[2] = m[4] = m[6] = "10101010";
	m[1] = m[3] = m[5] = m[7] = "01010101";
	while(t--) {
		char x0, x1;
		int y0, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		ii start = toCordinate(x0, y0), end = toCordinate(x1, y1);
		if (m[start.first][start.second] != m[end.first][end.second]) cout << "Impossible" << endl;
		else {
			if (x0 == x1 && y0 == y1) cout << "0 " << x0 << " " << y0 << endl;
			else {
				set<ii> n = getNeighbor(start);
				if (n.find(end) != n.end()) cout << "1 " << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
				else  {
					for (auto i : n) {
						set<ii> n2 = getNeighbor(i);
						if (n2.find(end) != n2.end()) {
							ci res = toReadable(i.first, i.second);
							cout << "2 " << x0 << " " << y0 << " " << res.first << " " << res.second << " " << x1 << " " << y1 << endl;
							break;
						}
					}
				}
			}
		}

	}
	return 0;
}