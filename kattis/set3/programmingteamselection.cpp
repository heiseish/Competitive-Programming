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
const int maxn = 1 << 15;
int dp[maxn], mat[16][16];
unordered_map<int, vpi> g;
int n;
int solve(int mask) {
	if (mask == (1 << n) - 1) return 1;
	if (dp[mask] != -1) return dp[mask];
	int& ans = dp[mask];
	ans = 0;
	forn(i, 0, n-1) {
		if (mask & (1 << i)) continue;
		for (auto &p : g[i]) {
			if ((mask & (1 << p.st)) || (mask & (1<<p.nd))) continue;
			mask|=1<<p.st;
			mask|=1<<p.nd;
			mask|=1<<i;
			ans|=solve(mask);
			mask&= ~(1 << p.st);
			mask&= ~(1 << p.nd);
			mask&= ~(1 << i);
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int m;
	while(cin>>m && m) {
		memset(dp, -1, sizeof dp);
		memset(mat, 0, sizeof mat);
		g.clear();
		int ct = 0;
		unordered_map<string, int> sti;
		forn(i, 1, m) {
			string a, b;
			cin>>a>>b;
			int j, k;
			if (sti.find(a) == sti.end()) {
				j=ct;
				sti[a]=ct++;
			} else j = sti[a];
			if (sti.find(b) == sti.end()) {
				k=ct;
				sti[b]=ct++;
			} else k = sti[b];
			mat[j][k]=1;
			mat[k][j]=1;
		}
		forn(i, 0, ct-1) forn(j, i+1, ct-1) forn(k, j+1, ct-1) {
			if (mat[i][j]&&mat[j][k]&&mat[k][i]) {
				g[i].pb({j, k});
				g[j].pb({i, k});
				g[k].pb({i, j});
			}
		}
		n=ct;
		cout<<(solve(0)?"possible":"impossible")<<'\n';
	}
	return 0;
}
