#include <bits/stdc++.h>
#define MIN -1001
#define RANGLE 1.5708
using namespace std;
double inf = 1 << 30;

struct V {
	int x,y;
};

struct E {
	V v1, v2;
};

double dist(V v1, V v2) {
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
};

double dist(V v, E e) {
	double a = dist(e.v1, e.v2);
	double a2 = pow(a, 2);
	double b = dist(v, e.v2);
	double b2 = pow(b, 2);
	double c = dist(v, e.v1);
	double c2 = pow(c, 2);
	return b * sin(acos((a2 + b2 - c2)/ (2 * b * a)));
};

bool isObtuse(V v, E e) {
	double a = dist(e.v1, e.v2);
	double a2 = pow(a, 2);
	double b = dist(v, e.v2);
	double b2 = pow(b, 2);
	double c = dist(v, e.v1);
	double c2 = pow(c, 2);
	double h2 = pow(dist(v, e), 2);
	return b2 - h2 >= a2 || c2 - h2 >= a2;
}
int main() {
	int c;
	cin >> c;
	while (c-- > 0) {
		vector<V> vi, vo;
		vector<E> ei, eo;
		int ni, no;
		cin >> ni;
		V prevV{MIN, MIN};
		while (ni-- > 0) {
			V tempV;
			cin >> tempV.x >> tempV.y;
			vi.push_back(tempV);
			if (prevV.x != MIN) ei.push_back({tempV, prevV});
			prevV = tempV;
		}
		ei.push_back({vi[0], prevV});
		prevV = {MIN, MIN};
		cin >> no;
		while (no-- > 0) {
			V tempV;
			cin >> tempV.x >> tempV.y;
			vo.push_back(tempV);
			if (prevV.x != MIN) eo.push_back({tempV, prevV});
			prevV = tempV;
		}
		eo.push_back({vo[0], prevV});
		double min = inf;
		for (auto i : vi) {
			for (auto j : eo) {
				if (!isObtuse(i, j)) {
					double temp = dist(i, j);
					if (temp < min) min = temp;
				}
			}
		}
		for (auto i : vo) {
			for (auto j : ei) {
				if (!isObtuse(i, j)) {
					double temp = dist(i, j);
					if (temp < min) min = temp;
				}  
			}
		}
		for (auto i : vi) {
			for (auto j : vo) {
				double temp = dist(i, j);
				if (temp < min) min = temp;
			}
		}
		printf("%.20f\n", min/2);


	}
	return 0;
}