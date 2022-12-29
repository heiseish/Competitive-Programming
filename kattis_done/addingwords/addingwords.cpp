#include <bits/stdc++.h>

using namespace std;

int main() {
	string temp;
	unordered_map<int, string> m;
	unordered_map<string, int> n;
	while (getline(cin, temp)) {
		stringstream in(temp);
        string inp;
        in >> inp;
		if (inp == "def") {
			string tmp;
			int h;
			in >> tmp >> h;
			if (n.find(tmp) != n.end()) m.erase(n[tmp]);
			m[h] = tmp;
			n[tmp] = h;
		} else if (inp == "calc") {
			vector<string> his;
			string a, b, c;
			int res = 0;
			bool valid =true;
			in >> a;
			// his.push_back(a);
			if (n.find(a) == n.end()) valid = false;
			else res = n[a];
			cout << a << " ";
			while (true) {
				in >> b;
				// his.push_back(b);
				cout << b << " ";
				if (b == "=") break;
				in >> c;
				cout << c << " ";
				if (n.find(c) == n.end()) valid =false;
				else if (b == "+") {
					res+= n[c];
				} else {
					res-= n[c];
				}
			}
			// for (auto i : his) cout << i << " ";
			if (!valid || m.find(res) == m.end()) cout << "unknown" << endl;
			else cout << m[res] << endl;
		} else if (inp == "clear") {
			m.clear();
			n.clear();
		}
	}
}