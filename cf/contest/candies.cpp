#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	bool le = true;
	vector<int> l, r;
	map<int, vector<int> > hm;
	for(int i = 0;i<n;i++) {
		int t;cin >> t;
		l.push_back(t);
		if (t > i) le = false;
	}
	for(int i = 0;i<n;i++) {
		int t;cin >> t;
		r.push_back(t);
		if (t >= n - i) le = false;
		hm[l[i] + r[i]].push_back(i);
	}
	
	vector<int> res (n, 0);
	for (auto i : hm) {
		for (auto j : i.second) {
			res[j] = n - i.first;
			if (res[j] <= 0) {
				le = false;
			}
		}
	}
	
	//forward
	map<int, int> nm;
	for (int i = 0; i < n;i++) {
		int ct = 0;
		for (auto j : nm) {
			if (j.first > res[i]) {
				ct+=j.second;
			}
		}
		if (nm.find(res[i]) == nm.end()) nm[res[i]] = 1;
		else nm[res[i]]++;
		if (ct != l[i]) {
			// cout << "Failing here l" << i << endl;
			le = false;
		}
	}
	// //backward
	nm.clear();
	for (int i = n-1; i >=0;i--) {
		int ct = 0;
		for (auto j : nm) {
			if (j.first > res[i]) {
				ct+=j.second;
			}
		}
		if (nm.find(res[i]) == nm.end()) nm[res[i]] = 1;
		else nm[res[i]]++;
		if (ct != r[i]) {
			// cout << "Failing here r" << i << endl;
			le = false;
		}
	}

	if (!le) {
		cout << "NO" << endl;
		// for (auto i : res) cout << i << " ";
		// cout << endl;
	} else {
		cout << "YES" << endl;
		for (auto i : res) cout << i << " ";
		cout << endl;
	}
	return 0;
}