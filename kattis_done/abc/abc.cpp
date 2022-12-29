#include <bits/stdc++.h>

using namespace std;
int main(){
	int a,b,c;
	unordered_map<char, int> h;
	string temp;
	cin >> a >> b >> c;
	cin >> temp;
	vector<int> t{a, b,c};
	sort(t.begin(), t.end());
	h['A'] = t[0];
	h['B'] = t[1];
	h['C'] = t[2];
	for (auto i : temp) {
		cout << h[i];
		if (i == temp[2]) cout << endl;
		else cout << " ";
	}
	return 0;
}