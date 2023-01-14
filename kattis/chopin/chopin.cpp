#include <bits/stdc++.h>
using namespace std;
int main() {
	string n;
	unordered_map<string, string> m;
	m["A#"] = "Bb";
	m["Bb"] = "A#";
	m["C#"] = "Db";
	m["Db"] = "C#";
	m["D#"] = "Eb";
	m["Eb"] = "D#";
	m["F#"] = "Gb";
	m["Gb"] = "F#";
	m["G#"] = "Ab";
	m["Ab"] = "G#";
	int c = 1;
	while(cin >> n && !cin.eof()) {
		string t;
		cin >>  t;
		if (m.find(n) != m.end()) {
			n = m[n];
			cout << "Case " << c++ << ": " << n << " " << t << endl;
		} else {
			cout << "Case " << c++ << ": UNIQUE" << endl;
		}
	}
	return 0;
}