/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 51;
int ex[maxn][maxn];
vector<string> b;
pi sta, en;
int n;
bool noNeed = false;
vpi staland, enland;
void dfs(int r, int c, int st=0) {
	ex[r][c]++;
	if (st == 0) staland.pb({r, c});
	else enland.pb({r, c});
	if (r == en.st && c == en.nd && st == 0) noNeed = true;

	if (r > 0 && !ex[r-1][c] && b[r-1][c] == '0') dfs(r-1, c, st);
	if (r < n-1 && !ex[r+1][c] && b[r+1][c] == '0') dfs(r+1, c, st);
	if (c > 0 && !ex[r][c-1] && b[r][c-1] == '0') dfs(r, c-1, st);
	if (c < n-1 && !ex[r][c+1] && b[r][c+1] == '0') dfs(r, c+1, st);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	
	cin>>n;
	cin>>sta.st>>sta.nd;
	sta.st--;
	sta.nd--;
	cin>>en.st>>en.nd;
	en.st--;
	en.nd--;
	b.resize(n);
	forn(i,0,n-1)cin>>b[i];
	dfs(sta.st, sta.nd);
	if (noNeed) {
		cout << "0\n";
		return 0;
	}
	dfs(en.st, en.nd, 1);
	int cost = INF;
	for (auto &p : staland) for (auto &v : enland) {
		cost=min(cost, (int) pow(p.st - v.st, 2) + (int) pow(p.nd - v.nd, 2));
	}
	cout << cost <<'\n';
	return 0;
}
