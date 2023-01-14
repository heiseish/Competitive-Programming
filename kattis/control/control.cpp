#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back

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
const int maxn = 5e5 + 7;
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
	int n;
	scanf("%d", &n);
	forn(i, 0, maxn - 1) {
		s[i] = 1;
		d[i] = i;
	}
	int r = 0;
	while(n--) {
		int m;
		scanf("%d", &m);
		vi temp;
		unordered_map<int, int> f;
		bool can = true;
		forn(i, 0, m - 1) {
			int t;
			scanf("%d", &t);
			temp.pb(t);
			if (f.find(find(t)) == f.end()) f[find(t)] = 1;
			else f[find(t)]++;

		}
		for(auto i : f) {
			if (i.second != s[find(i.first)]) {
				can = false;
				break;
			}
		}
		if (!can) continue;
		forn(i, 0, (int)temp.size() - 2) join(temp[i], temp[i + 1]);
		if (can) r++;
	}
	printf("%d\n", r);
	return 0;
}
