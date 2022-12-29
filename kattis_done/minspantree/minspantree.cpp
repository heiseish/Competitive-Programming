/** 
it is foolish to fear what we have to see and know”
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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
int n, m;
const int maxn = 2e4 + 7;
int g[maxn];

int find(int index) {
	if (g[index] == index) return index;
	return g[index] = find(g[index]);
}

bool isSameSet(int a, int b) {
	return find(a) == find(b);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	g[a] = b;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while(scanf("%d %d", &n, &m) && (n|| m)) {
		vector<pair<int, pi> > el;
		forn(i, 0, n - 1) g[i] = i;
		forn(i, 1, m) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			if (a < b) el.pb({ w, {a , b}});
			else el.pb({ w, {b, a }});
		}
		sort(all(el));
		vpi res;
		int ct = 0, cost = 0;
		for (auto i : el) {
			if (!isSameSet(i.nd.st, i.nd.nd)) {
				join(i.nd.st, i.nd.nd);
				res.pb({ i.nd.st, i.nd.nd });
				ct++;
				cost+=i.st;
			}
		}
		if (ct < n - 1) {
			printf("Impossible\n");
			continue;
		}
		sort(all(res));
		printf("%d\n", cost);
		for (auto i : res) {
			printf("%d %d\n", i.st, i.nd);
		}
	} 
	return 0;
}
