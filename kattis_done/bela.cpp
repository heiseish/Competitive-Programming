#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	char d;
	cin >> N >> d;
	int p = 0;
	N*=4;
	unordered_map<char, int> nodom;
	nodom['A'] = 11;
	nodom['K'] = 4;
	nodom['Q'] = 3;
	nodom['J'] = 2;
	nodom['T'] = 10;
	nodom['9'] = 0;
	nodom['8'] = 0;
	nodom['7'] = 0;
	unordered_map<char, int> dom;
	dom['A'] = 11;
	dom['K'] = 4;
	dom['Q'] = 3;
	dom['J'] = 20;
	dom['T'] = 10;
	dom['9'] = 14;
	dom['8'] = 0;
	dom['7'] = 0;
	while(N--) {
		string t;
		cin >> t;
		if (t[1] == d) p+=dom[t[0]];
		else p+=nodom[t[0]];
	}
	cout << p << endl;
	return 0;
}