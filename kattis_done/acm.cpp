#include <bits/stdc++.h>
using namespace std;
int main() {
	int temp, pr = 0, ti = 0;
	set<char> s;
	unordered_map<char, int> pe;
	while (scanf("%d", &temp), temp != -1) {
		char p;
		string r;
		cin >> p >> r;
		if (s.find(p) != s.end()) continue;
		else if (r == "wrong") {
			if (pe.find(p) == pe.end()) pe[p] = 0;
			pe[p] += 20;
		} else if (r == "right") {
			if (pe.find(p) != pe.end()) ti+=pe[p];
			pr++;
			ti += temp;
			s.insert(p);
		}
	}
	cout << pr << " " << ti << endl;
	return 0;
}