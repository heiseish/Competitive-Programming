/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
const int maxn = 1003;
int taken[maxn][maxn];
void plot(pi start, pi end, vpi& a) {
	while(start != end) {
		taken[start.st][start.nd]++;
		pi temp = start;
		a.pb(temp);
		if (start.st > end.st) start.st--;
		else if (start.st < end.st) start.st++;
		else if (start.nd > end.nd) start.nd--;
		else if (start.nd < end.nd) start.nd++;
	}
	a.pb(end);
	taken[end.st][end.nd]++;
}

vpi solve(pi start, pi end, pi mid) {
	rsa(taken, 0);
	vpi res;
	if (abs(end.nd - mid.nd) < abs(start.nd - mid.nd)) plot(end, start, res);
	else plot(start, end, res);
	pi p;
	queue<pi> q;
	q.push(mid);
	int explored[maxn][maxn];
	rsa(explored, 0);
	while(!q.empty()) {
		pi cur = q.front();q.pop();
		auto [x, y] = cur;
		if (x < 0 || x > 1000 || y < 0 || y > 1000 || explored[x][y]++)  {
				continue;
			}
		if (taken[x][y]) {
			p = cur;
			break;
		}
		q.push(pi(x + 1, y));
		q.push(pi(x - 1, y));
		q.push(pi(x, y + 1));
		q.push(pi(x, y - 1));
	}
	plot(mid, p, res);
	res.pop_back();
	return res;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<pi> p(3);
	forn(i, 0, 2) cin >> p[i].st >> p[i].nd;
	vpi f = solve(p[0], p[1], p[2]);
	vpi s = solve(p[0], p[2], p[1]);
	vpi t = solve(p[2], p[1], p[0]);
	int ans = min({f.size(), s.size(), t.size()});
	cout << ans << '\n';
	if (f.size() == ans) {
		for (auto &v : f) cout << v.st <<' ' << v.nd << '\n';
	} else if (s.size() == ans) {
		for (auto &v : s) cout << v.st <<' ' << v.nd << '\n';
	} else  {
		for (auto &v : t) cout << v.st <<' ' << v.nd << '\n';
	}
	return 0;
}
