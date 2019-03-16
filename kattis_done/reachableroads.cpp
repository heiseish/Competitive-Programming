/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?
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

const int maxn = 1e3 + 3;
int g[maxn] , r[maxn];
int n, m;
int ct;

int find(int index) {
	if (g[index] == index)
		return index;
	return g[index] = find(g[index]);
}

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	ct--;
	if (r[a] > r[b]) {
		g[b] = a;
		r[a] += r[b];
	} else {
		g[a] = b;
		r[b] += r[a];
	}
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		ct = n;
		forn(i, 0, n - 1)
			g[i] = i;
		scanf("%d", &m);
		forn(i, 0, m - 1) {
			int a, b;
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		printf("%d\n", ct - 1);
	}
	return 0;
}
