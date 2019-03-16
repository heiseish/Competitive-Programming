/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.        
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
ll f[1 << 15][17];
ll res[16];
int n;
ll solve(int used , int prev = 16) {
	if (used == (1 <<n) - 1) 
		return 1;
	if (f[used][prev] != -1) return f[used][prev];
	ll& ans = f[used][prev] = 0;
	if (prev != 16) {
		int prog = __builtin_popcount(used)%2==0 ? 1 : -1;
		for(int i = prev + prog; i < n && i >= 0; i+=prog) {
			if (!(used & (1 << i))) ans += solve(used | (1 << i),  i);
		}
	} else
		forn(i,0,n-1) {
			ans += solve(used | (1 << i), i);
		}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	for(int i=  3;i<= 15;i+=2) {
		n = i;
		memset(f, -1, sizeof f);
		res[i] = solve(0);
	}
	int t;
	while(cin >> n  && n) {
		forn(i,1,n) cin >> t;
		cout << res[n] <<'\n';
	}
	return 0;
}
