#include <bits/stdc++.h>
using namespace std;

struct point {
	int index;
	int x;
	int y;
};

double dist(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int find(vector<int>& d, int a) {
	if (d[a] == a) return a;
	else return d[a] = find(d, d[a]);
}
void Union(vector<int>& d, int a, int b) {
	a = find(d, a);
	b = find(d, b);
	if (a == b) return;
	d[a] = b;
}

struct edge {
	point a;
	point b;
	double distance;
};
bool compareTo(edge lhs,  edge rhs) {
  return lhs.distance < rhs.distance;
}

int main(){
	int q;
	cin >> q;
	while (q-- > 0) {
		vector<edge> edgeList;
		vector<point> map;
		int s, p;
		cin >> s >> p;
		vector<int> d;
		for (int i=0;i<p;i++) {
			int x, y;
			cin >> x >> y;
			d.push_back(i);
			point temp{i, x, y};
			for (auto it : map) {
				edge tmp{temp, it, 0.0};
				tmp.distance = dist(temp, it);
				edgeList.push_back(tmp);
			}
			map.push_back(temp);
			
		}
		sort(edgeList.begin(), edgeList.end(), compareTo);
		vector<edge> result;
		for (auto i : edgeList) {
			if (find(d, i.a.index) != find(d, i.b.index)) {
				result.push_back(i);
				Union(d, i.a.index, i.b.index);
			}
		}
		for (int i=1;i<s;i++) result.pop_back();
		printf("%.2f\n", result.back().distance);
	}
	return 0;
}