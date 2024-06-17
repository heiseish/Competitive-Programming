/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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
const int MAXN = 1e5 + 7;
struct E {
	int d, w, type;
	bool operator<(const E &other) const {
		return w > other.w || (w == other.w && d > other.d);
	}
};
vector<E> e[MAXN];
E a[MAXN];
map<E, int> cur;
int n, m, k;

ll f[2][MAXN];// f[i][j] represents a state with i ranges from 1 to 200, and j from 1 to 1e5.
ll ans = 1LL << 60;

void insert(E x) {
	if (cur.count(x)) cur[x]++;
	else cur[x] = 1;
}

void erase(E x) {
	cur[x]--;
	if (cur[x] == 0) cur.erase(x);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n>>m>>k;
	forn(i, 1, k) {
		int s,t,d,w;
		cin>>s>>t>>d>>w;
		e[s].pb({d, w, 1});
		e[t+1].pb({d, w, -1});
	}
	forn(i,1, n) {
		for (auto &p : e[i]) {
			if (p.type == 1)
				insert(p);
			else
				erase(p);
		}
		if (!cur.empty()) a[i] = cur.begin()->first;
		else a[i] = {i, 0, 0};
	}
	memset(f, 0x3f, sizeof(f));
	f[0][1] = 0;
	for (int j = 0; j <= m; j++){
		memset(f[(j ^ 1) & 1], 0x3f, sizeof(f[(j ^ 1) & 1]));
		for (int i = 1; i <= n; i++){
			f[(j ^ 1) & 1][i + 1] = min(f[(j ^ 1) & 1][i + 1], f[j & 1][i]);
			f[j & 1][a[i].d + 1] = min(f[j & 1][a[i].d + 1], f[j & 1][i] + a[i].w);
		}
		ans = min(ans, f[j & 1][n + 1]);
	}
	cout << ans<<'\n';
	return 0;
}
