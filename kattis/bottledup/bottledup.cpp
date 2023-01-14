/** 
Justice isn’t something that you can just proclaim. It’s a feeling you should keep near your heart.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
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

/**
Start coding from here
*/

const int maxc = 1e6 + 7;
vpi dp(maxc, mp(-1, -1));
int s, v1, v2;

pi min(pi lhs, pi rhs) {
	return (lhs.st + lhs.nd < rhs.st + rhs.nd) ? lhs : rhs;
}

pi add(pi lhs, pi rhs) {
	return { lhs.st + rhs.st, lhs.nd + rhs.nd};
}
pi solve(int cost) {
	if (cost == 0) return mp(0, 0);
	if (cost < v1 && cost < v2) return mp(maxc, maxc);
	if (dp[cost] != mp(-1, -1))  return dp[cost];
	pi& ans = dp[cost];
	ans.st = maxc;
	ans.nd = maxc;
	if (cost >= v1) ans = min(ans, add(mp(1, 0), solve(cost - v1)));
	if (cost >= v2) ans = min(ans, add(mp(0, 1), solve(cost - v2)));
	return ans;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d %d %d", &s, &v1, &v2);
	pi res = solve(s);
	if (res.st == maxc || res.nd == maxc) printf("Impossible\n");
	else printf("%d %d\n", res.st, res.nd); 
	return 0;
}
