/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
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
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int n;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	forn(i,1,n) cin>>a[i];
	forn(i,1,n) cin>>b[i];
	map<pi, int> g;
	int ct = 0;
	forn(i,1,n) {
		if (a[i] == 0 && b[i] == 0) {
			ct++;
			continue;
		} else if (a[i] == 0) continue;
		else if (b[i] == 0) {
			g[{0, 0}]++;
			continue;
		}
		int negative = (a[i] > 0 && b[i] < 0) || (a[i] < 0 && b[i] > 0);
		int x = abs(a[i]);
		int y = abs(b[i]);
		int gc = gcd(x, y);
		x/=gc;
		y/=gc;
		if (negative) x = -x;
		g[{x, y}]++;
	}
	int ans = 0;
	if (g.empty()) ans = ct;
	else 
	for (auto &v : g) ans= max(ans, v.nd + ct);
	cout << ans <<'\n';
	return 0;
}
