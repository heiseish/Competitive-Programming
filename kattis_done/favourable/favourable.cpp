#include <bits/stdc++.h>
// #define ll long long

using namespace std;

vector<int> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<int> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(stoi(item));
    }
    return tokens;
}
map<int, int> endings;
map<int, vector<int> > divergence;
map<int, long long> numPaths;

long long dynamicFind(int index) {
	if (endings.find(index) != endings.end()) {
		return endings[index]; 
	}
	long long sum = 0;
	for (auto i : divergence[index]) {
		if (numPaths.find(i) == numPaths.end()) {
			numPaths[i] = dynamicFind(i);
		}
		sum += numPaths[i];
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		endings.clear();
		divergence.clear();
		numPaths.clear();
		
		int start = 0;
		for (int j = 0; j < s; j++) {
			int page;
			cin >> page;
			cin.ignore();
			string temp;
			getline(cin, temp);
			if (temp == "catastrophically" || temp == "favourably") endings[page] = temp == "catastrophically" ? 0 : 1;
			else {
				vector<int> tmp = split(temp, ' ');
				divergence[page] = tmp;
			}
		}
		cout << dynamicFind(1) << endl;
	}
	return 0;
}