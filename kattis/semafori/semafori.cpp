#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> iii;
int main() {
	int n,l;
	cin >> n >> l;
	vector<iii> tl;
	while(n--) {
		int a,b,c;
		cin >> a >> b >> c;
		tl.push_back(make_tuple(a, b, c));
	}
	int t = 0, d = 0, ntl = 0;
	for (auto i : tl) {
		t+=get<0>(i) - d;
		d = get<0>(i);
		// bool g = t %(get<1>(i) + get<2>(i)) < get<1>(i) ? false : true;
		// if (!g) t+= get<1>(i) - (t %(get<1>(i) + get<2>(i)));
		t+=max({ get<1>(i) - (t %(get<1>(i) + get<2>(i))), 0});
	}
	t+=l-d;
	cout << t << endl;
	return 0;
}