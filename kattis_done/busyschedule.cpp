#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, string> iis;
bool se (const iis& lhs, const iis& rhs) {
	if (lhs.second == rhs.second) return lhs.first.first * 60 + lhs.first.second <
	rhs.first.first * 60 + rhs.first.second;
	else return lhs.second < rhs.second;
}
int main() {
	int n;
	bool first = true;
	while(cin >> n && n) {
		if (!first) {
			cout << endl;
		} else first = false;
		vector<iis> s;
		while(n--) {
			int h, m;
			string ni;
			scanf("%d:%d", &h, &m);
			cin >> ni;
			if (h == 12) h = 0;
			s.push_back({{h, m}, ni});
		}
		sort(s.begin(), s.end(), se);
		for (auto& i : s) {
			if (i.first.first == 0) i.first.first += 12;
			
			printf("%d:%02d ", i.first.first, i.first.second);
			cout << i.second << endl;
			
			
		}
	}
	return 0;
}