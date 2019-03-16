#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > n;
vector<vector<int> > m;
vector<bool> e;
vector<bool> hb;
vector<int> g;
void initializeMap(int r) {
	int a = r;
	int cur = 1;
	int c = 0;
	int mid = (pow(r, 3) - pow(r - 1, 3) + 1) / 2;
	for (int i=0; i < 2 * r - 1;i++) {
		if (cur < mid - r + 1) {
			for (int  j = 0; j < a;j++) {
				m[i][j] = cur++;
			}
			a++;
		} else {
			for (int j = c++; j < a; j++) {
				m[i][j] = cur++;
			}
		}
	}
	for (int i =0; i < 2 * r - 1;i++) {
		for (int j = 0; j < 2 * r - 1;j++) {
			if (j < 2 * r - 2 && m[i][j + 1] != -1) n[m[i][j] - 1].push_back(m[i][j + 1] - 1);
			if (i < 2 * r - 2 && m[i + 1][j] != -1) n[m[i][j] - 1].push_back(m[i+1][j] - 1);
			if (i < 2 * r - 2 && j < 2 * r -2 &&  m[i + 1][j] != -1) n[m[i][j]-1].push_back(m[i+1][j+1]-1);
			if (j > 0 && m[i][j-1]!=-1) n[m[i][j]-1].push_back(m[i][j-1]-1);
			if (i > 0 && m[i-1][j]!=-1) n[m[i][j]-1].push_back(m[i-1][j]-1);
			if (i > 0 && j>0& m[i-1][j-1]!=-1) n[m[i][j]-1].push_back(n[i-1][j-1]-1);
		}
	}
}
int ct = 0;

int DFS(int i, int peri) {
	e[i] = true;
	g[i] = ct;
	peri += 6 - n[i].size();
	for (auto v : n[i]) {
		if (hb[i] != hb[v-1]) peri++;
		else if (!e[v-1]) peri += DFS(v-1, peri);
	}
	return peri;

}
int main() {
	int r, k;
	cin >> r >> k;
	int num = pow(r,3) - pow(r-1,3);
	m.assign(2 * r  - 1, vector<int> (2 * r - 1, -1));
	vector<int> hi;
	hb.assign(num, false);
	e.assign(num, false);
	g.assign(num, -1);
	for(int i=0;i<k;i++) {
		int temp; cin >> temp;
		hi.push_back(temp);
		hb[temp-1]=true;

	}
	initializeMap(r);
	vector<int> res;
	for (int  i = 0; i < num;i++) {
		if (!e[i]) {
			ct++;
			res.push_back(DFS(i, 0));
		}
	}

	return 0;
}