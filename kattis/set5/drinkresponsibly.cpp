/** 
Those who do not understand true pain can never understand true peace.        
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
#define mp make_pair

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

struct Drink {
	string n;
	int t, c;
};
vector<Drink> dr, a;
const int maxd= 9;
const int maxu = 20 * 60 + 3;
const int maxm = 1000 + 7;
int dp[maxd][maxm][maxu];
int n;
int m, u, d;
int solve(int cur, int m, int u) {
	if (m < 0 || u < 0 || cur >= d) return 0;
	if (u == 0 && m == 0) return dp[cur][m][u] = 1;
	if (dp[cur][m][u] != -1) return dp[cur][m][u];
	int& ans = dp[cur][m][u] = 0;
	ans |= solve(cur, m - dr[cur].c, u - dr[cur].t);
	ans |= solve(cur+1, m, u);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	memset(dp, -1, sizeof dp);
	double M, U;
	cin>>M>>U>>d;
	m = 100.0 * M;
	u = 60.0 * U;
	string s, na;
	double te;
	int f;
	forn(i, 0, d-1) {
		cin >> na >>f >> s >> te;
		f*=60;
		if (s == "1/2") f/=2;
		else if (s == "1/3") f/=3;
		Drink temp;
		temp.t = f;
		temp.c = 100.0 * te;
		temp.n = na;
		dr.pb(temp);
	}
	
	unordered_map<string, int> g;
	solve(0, m, u);

	if (dp[0][m][u] != 1) {
		cout << "IMPOSSIBLE\n";
	} else {
		int cur = 0, uk = u, curm = m;
		while(cur < d) {
			if (uk >= dr[cur].t && curm >= dr[cur].c && dp[cur][curm - dr[cur].c][uk - dr[cur].t] == 1) {
				g[dr[cur].n]++;
				uk-=dr[cur].t;
				curm-=dr[cur].c;
			} else cur++;
		}
		for (auto &n : g) cout << n.st << ' ' << n.nd<<'\n';
	}

	return 0;
}
