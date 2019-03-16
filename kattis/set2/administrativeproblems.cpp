/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
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

struct c {
	int p, q, k;
};

struct ev {
	int ti;
	char t;
	string C;
	int d;
	bool operator<(const ev& rhs) const {
		return ti<rhs.ti;
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		int n, m;
		cin>>n>>m;
		unordered_map<string, c> cars;
		forn(i, 1, n) {
			string s;
			cin>>s;
			c temp;
			cin>>temp.p>>temp.q>>temp.k;
			cars[s] = temp;
		}

		map<string, vector<ev> > spies;
		forn(i, 1, m) {
			int t;
			string s;
			char e;
			ev temp;
			cin>>temp.ti>>s>>temp.t;
			if (temp.t=='p') cin >> temp.C;
			else cin>>temp.d;
			spies[s].pb(temp);
		}

		for (auto &s : spies) {
			vector<ev> &events = s.nd;
			sort(all(events));
			bool usingCar = false;
			bool can = true;
			ll ans = 0LL;
			string curcar = "";
			for (auto &ss : events) {
				if (ss.t == 'p') {
					if (usingCar) {
						can = false;
						break;
					} else {
						usingCar = true;
						ans += cars[ss.C].q;
						curcar = ss.C;
					}
				} else if (ss.t == 'a') {
					if (!usingCar) {
						can = false;
						break;
					} else {
		
						ans += (ll) ceil(1.0 * ss.d * cars[curcar].p / 100.0);
	
					}
				} else {
					if (!usingCar) {
						can = false;
						break;
					} else {
						ans += cars[curcar].k * ss.d;
						usingCar = false;
					}
				}
			}
			if (usingCar) can = false;
			if (!can) cout << s.st << " INCONSISTENT\n";
			else cout << s.st << ' ' << ans << '\n';
		}
	}
	return 0;
}
