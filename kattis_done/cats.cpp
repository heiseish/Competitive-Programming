/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.
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
const int maxc = 2e3 + 7;
int g[maxc];
int m, c;

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
	// ios_base::sync_with_stdxio(false); cin.tie(0); cout.tie(0);
	int t;
	scanf("%d", &t);
	while(t--) {
		vector<pair<int, pi> > e;
		scanf("%d %d", &m, &c);
		forn(i, 0, c - 1) g[i] = i;
		forn(i, 1, c * (c - 1) / 2) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			e.pb({w , { a, b }});
		}
		sort(all(e));
		int cost = 0;
		forn(j, 0, (int) e.size() - 1) {
			pair<int, pi> i = e[j];
			if (!isSameSet(i.nd.st, i.nd.nd)) {
				join(i.nd.st, i.nd.nd);
				cost += i.st;
			}
		}
		if (cost + c <= m) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
