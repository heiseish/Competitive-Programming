#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef unordered_map<char, ii> um;
string m;
um mapping;

int distChar(char a, char b) {
	ii ca = mapping[a], cb = mapping[b];
	return abs(ca.first - cb.first) + abs(ca.second - cb.second);
}
int dist(string a, string b) {
	int c = 0;
	for (int i=0;i<a.length();i++) {
		c+=distChar(a[i], b[i]);
	}
	return c;
}
bool compareString (const string& lhs, const string& rhs) {
	if (dist(lhs, m) == dist(rhs, m)) return lhs < rhs;
	else return dist(lhs, m) < dist(rhs, m);
}
int main() {
	vector<string> dict = {
		"qwertyuiop",
		"asdfghjkl",
		"zxcvbnm"
	};
	for (int i = 0;i< dict.size();i++) {
		for (int j = 0; j< dict[i].length();j++) {
			mapping[dict[i][j]] = { i, j};
		}
	}
	
	int t;
	cin >> t;
	while(t--) {
		int l;
		cin >> m >> l;
		vector<string> c;
		while(l--) {
			string temp;
			cin >> temp;
			c.push_back(temp);
		}
		sort(c.begin(), c.end(), compareString);
		for (auto i : c) {
			cout << i << " " << dist(i, m) << endl;
		}
	}
	return 0;
}