#include <bits/stdc++.h>
#define forn(i, l, r) for(int i = l; i <= r;i++)
using namespace std;
typedef long l;
typedef long long lld;
typedef pair<l, l> ll;

struct comp{
	lld x;
	lld y;
	int idx;
};
bool compare(const comp& lhs, const comp& rhs) {
	return lhs.x - lhs.y < rhs.x - rhs.y;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<comp> a;
	vector<comp> b;
	vector<lld> s(n);
	forn(i, 0, n - 1){
		lld x, y;
		scanf("%lli %lli", &x, &y);
		a.push_back({x, y, i});
		b.push_back({x, y, i});
	}
	sort(a.begin(), a.end(), compare);
	lld curXsum = 0, curYsum = 0;
	forn(i, 1, n - 1) curYsum += a[i].y;
	forn(i, 0, n - 1) {
		s[a[i].idx] = curXsum + curYsum + a[i].y * i + a[i].x * (n - 1 - i);
		curXsum += a[i].x;
		if (i < n - 1) curYsum -= a[i + 1].y;
	}
	forn(i, 0, m - 1) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--; r--;
		s[l] -= min(b[l].x + b[r].y, b[l].y + b[r].x);
		s[r] -= min(b[l].x + b[r].y, b[l].y + b[r].x);
	}

	forn(i, 0, n - 1) printf("%lli ", s[i]);
	printf("\n");
	return 0;
}