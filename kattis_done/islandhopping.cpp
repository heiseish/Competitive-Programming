/** 
It does not do to dwell on dreams and forget to live.
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
typedef pair<double, double> pdd;
const int maxc = 750 + 7;;
int g[maxc];

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

double dist(pdd lhs, pdd rhs) {
	return sqrt(pow(lhs.st - rhs.st, 2) + pow(lhs.nd - rhs.nd, 2));
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	while(n--) {
		int m;
		scanf("%d", &m);
		vector<pdd> v(m);
		forn(i, 0, m - 1) scanf("%lf %lf", &v[i].st, &v[i].nd), g[i] = i;
		vector<pair<double, pi> > e;
		forn(i, 0, m - 1)
			forn(j, 0, m - 1)
				if(i != j)
					e.pb({ dist(v[i], v[j]), {i, j} });
		sort(all(e));
		double cost = 0.0;
		for (auto i : e)
			if (!isSameSet(i.nd.nd, i.nd.st)) {
				cost += i.st;
				join(i.nd.nd, i.nd.st);
			}
		printf("%.10f\n", cost);
	}
	return 0;
}
