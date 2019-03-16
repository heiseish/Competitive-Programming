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
struct State {
	int s,w,c;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	int ct=1;
	while(tc--) {
		int n, m, c;
		cin>>n>>m>>c;
		vector<pair<int, string> > ans;
		forn(i, 1, c) {
			string s;
			cin>>s;
			string name=s.substr(0, s.find(":"));
			int a = stoi(s.substr(s.find(":") + 1, s.find(",")));
			int b = stoi(s.substr(s.find(",") + 1));
			int res = INF;
			int cur = n;
			int cost = 0;
			while(cur>=m) {
				res = min(res, cost + (cur - m) * a);
				cur/=2;
				cost+=b;
			}
			
			ans.pb({res, name});
		}
		sort(all(ans));
		cout << "Case " << ct++ << '\n';
		for(auto &aa : ans) cout << aa.nd << ' ' <<aa.st<<'\n';
	}
	return 0;
}
