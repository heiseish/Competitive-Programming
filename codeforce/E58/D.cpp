/** 
When a man learns to love, he must bear the risk of hatred.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x
#define sz(x) (int)x.size()

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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
unordered_map<int, vi> g;
vi visited;
vi a;
void dfs(int index, int gc) {
	for (auto &v:g){
		if (!visited[v]++) {
			dfs(index, gcd(gc, a[v]));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	visited.assign(n, 0);
	a.resize(n);
	forn(i, 0, n-1) cin>>a[i];
	forn(i,1,n-1){
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, a[0]);
	return 0;
}
