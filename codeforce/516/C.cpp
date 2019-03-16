#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<char, int> r;
	for (auto i : s) {
		if (r.find(i) == r.end()) r[i] = 1;
		else r[i]++;
	}
	map<int, vector<char> > rr;
	for (auto i : r) rr[i.second].push_back(i.first);
	int t = rr.rbegin()->first;
	string res = "";
	while(t > 0 && res.length() != n) {
		while (rr.find(t - 1) != rr.end() && rr.find(t) != rr.end() && !rr[t - 1].empty() && !rr[t].empty()) {
			char f = rr[t-1][rr[t - 1].size() - 1];
			char s = rr[t][rr[t].size() - 1];
			for (int i = 0; i < 2 * t - 1; i++) {
				res += (i%2==0 ? s : f);
			}
			rr[t - 1].pop_back();
			rr[t].pop_back();
		} 
		if (rr.find(t) == rr.end() || rr[t].empty()) {
			t--;
			continue;
		}
		// string temp = "";
		// for (auto i : rr[t]) temp += i;
		// string rtemp = "";
		// for(int i = temp.length() - 1; i >= 0;i--) rtemp += temp[i];
		// for (int i = 0; i < t; i++) {
		// 	res += (i%2==0 ? temp : rtemp);
		// }
		for (auto i : rr[t]) {
			res += string(t, i);
		}
		t--;
	}
	cout << res << endl;
	return 0;
}