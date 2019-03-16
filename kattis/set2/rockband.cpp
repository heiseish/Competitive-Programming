/** 
Wherever someone is still thinking of you, that place is your home.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int m, s;
	cin>>m>>s;
	vector<vi> songs(m, vi(s));
	vi pos(s + 1, 0);
	forn(i, 0, m - 1) {
		forn(j, 0, s-1) {
			cin>>songs[i][j];
			pos[songs[i][j]] = max(pos[songs[i][j]], j);
		}
	}
	int ans = 0;
	int curMax = 0;
	for(;ans <= s;ans++) {
		forn(i, 0, m-1) 
			curMax = max(pos[songs[i][ans]], curMax);
		if (curMax == ans) 
			break;
	}
	vi res;
	forn(i, 0, ans) res.pb(songs[0][i]);
	cout << ans + 1<<'\n';
	sort(all(res));
	for (auto &v : res) cout <<v << ' ';
	cout <<'\n';
	return 0;
}
