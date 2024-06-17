/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone
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
const int maxn = 1e5 + 7;
int s[maxn], r[maxn];
unordered_map<int, vi> sub;
vector<vi> gr;
/**
Solved
*/
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	scanf("%d %d", &n, &m);
	forn(i, 1, n) {
		scanf("%d %d", &s[i], &r[i]);
		sub[s[i]].pb(r[i]);
	}
	int maxheight = 0;
	for (auto i : sub) {
		vi temp = i.nd;
		sort(all(temp), greater<int>());
		maxheight = max(maxheight, (int) temp.size());
		gr.pb(temp);
	}
	vector<ll> dp(gr.size(), 0);
	ll ans = 0L;
	forn(k, 0, maxheight - 1)  {
		ll cur = 0L;
		forn(i, 0, (int) gr.size() - 1) {
			if (gr[i].size() <= k )
				continue;
			dp[i] += gr[i][k];
			if (1.0L * dp[i] > 0L)
				cur += (1.0L * dp[i]);
		}
		ans = max(ans, cur);
	}
	
	printf("%lld\n", ans);
	return 0;
}
