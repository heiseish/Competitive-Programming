#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unordered_map<int, vector<int> > um;

struct Property {
	int o;
	string t;
	ll index, b, r, v;
};
struct Edge {
	int v1, v2;
};
int main() {
	ll N, M, K, sa, sb;
	cin >> N >> M >> K >> sa >> sb;
	vector<Property> v(N, { });
	um e;
	while (M-- > 0) {
		ll v1,v2;
		cin >> v1 >> v2;
		e[v1].push_back(v2);
	}
	for (ll i=0;i<N;i++) {
		v[i].o = 0;
		v[i].index = i;
		cin >> v[i].t;
		if (v[i].t == "SALARY") {
			cin >> v[i].v;
		} else if (v[i].t == "PROPERTY") {
			cin >> v[i].b >> v[i].r;
		} else if (v[i].t == "TAX") {
			cin >> v[i].v;
		}
	}
	while (K-- > 0) {
		
	}
	
	return 0;
}