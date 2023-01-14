#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 1e6 + 7;
int d[maxn];
int s[maxn];
int find(int index) {
	if (d[index] == index) return index;
	return d[index] = find(d[index]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	d[a] = b;
	s[b] += s[a];
}
bool isSameSet(int a, int b) {
	return find(a) == find(b);
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	forn(i, 0, n - 1) d[i] = i;
	while(m--) {
		char q;
		int a, b;
		scanf(" %c %d %d", &q, &a, &b);
		if (q == '?') {
			if (isSameSet(a, b)) {
				printf("yes\n");
			} else printf("no\n");
		} else {
			join(a, b);
		}
	}
	return 0;
}
