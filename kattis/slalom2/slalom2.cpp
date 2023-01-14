/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back
#define nd second
#define st first

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
vi ski;
vpll g;
int w, vh, n;
int s;

bool check(int speed, ld* l, ld* r, int gate) {
	*r += (1.0 * vh * (g[gate].nd - g[gate - 1].nd)) / speed;
	*l -= (1.0 * vh * (g[gate].nd - g[gate - 1].nd)) / speed;
	*r = *r < g[gate].st + w ? *r : 1.0 * (g[gate].st + w);
	*l = *l >  g[gate].st ? *l : 1.0 * g[gate].st;
	return *l <= *r;
}

bool can(int m) {
	ld l = 1.0 * g[0].st, r = 1.0 * (g[0].st + w);
	forn(i, 1, g.size() - 1) {
		if (!check(ski[m], &l, &r, i)) return false;
	}
	return true;
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	scanf("%d %d %d", &w, &vh, &n);
	g.resize(n);
	forn(i, 0, n - 1) scanf("%lld %lld" , &g[i].first, &g[i].second);
	scanf("%d", &s);
	ski.resize(s);
	forn(i, 0, s-1) scanf("%d", &ski[i]);
	sort(ski.begin(), ski.end());
	int l = -1, r = ski.size();
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		// cout << "l is " << l << " and r is " << r << endl;
		// cout << "m is " << m << endl;
		bool res = can(m);
		if (res) l = m;
		else r = m;
	}
	if (l == -1) printf("IMPOSSIBLE\n");
	else printf("%d\n", ski[l]);
	return 0;
}
