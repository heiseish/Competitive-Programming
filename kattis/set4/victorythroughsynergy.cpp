/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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

const int INF = 1 << 30;
/**
Start coding from here
*/
struct player {
	string p, c, l, t;
};
vector<player> p(10);
const int maxn = 11;
vi g[11];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int c;
	cin>>c;
	forn(i, 0, c-1) {
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, 0, 9) {
		string pl, co, l, t;
		cin>>pl>>co>>l>>t;
		player tt = {pl, co, l, t};
		p[i] =  tt;
	}
	int deg[11];
	vi idx(10);
	forn(i, 0, 9) {
		deg[i] = sz(g[i]);
		idx[i]=i;
	}
	do {
		bool can = true;
    	forn(i, 0, 9) {
			int syn = 0;
			int j = idx[i];
			// for (auto &v : g[j]) {
			// 	if (p[v].t == p[j].t && p[v].c == p[j].c) syn += 3;
			// 	else if (p[v].c == p[j].c && p[v].l == p[j].l) syn += 2;
			// 	else if (p[v].t == p[j].t) syn+=2;
			// 	else if (p[v].l == p[j].l) syn++;
			// 	else if (p[v].c == p[j].c) syn++;
			// }
			for (auto &v : g[i]) {
                if (p[idx[v]].t == p[idx[i]].t) syn+=2;
                if (p[idx[v]].c == p[idx[i]].c) syn++;
                if (p[idx[v]].l == p[idx[i]].l) syn++;
            }
			if (syn < deg[i]) {
				can = false;
				break;
			}
		}
		if (can) {
			cout << "yes\n";
			return 0;
		}
  	} while (next_permutation(all(idx)));
	cout << "no\n";
	return 0;
}
