/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
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

const int NEGMAX = 5e4 +3;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	vector<string> e;
	unordered_map<string, int> dict;
	while(N--) {
		char t;
		cin >> t;	
		if (t == 'E') {
			string temp;
			cin >> temp;
			e.pb(temp);
			dict[temp] = e.size();
		} else if (t == 'D') {
			int p;
			cin >> p;
			while(p--) {
				dict[e.back()] = NEGMAX;
				e.pop_back();
			}
		} else {
			int k;
			cin >> k;
			int maxp = 0, maxf = NEGMAX;
			bool can = true;
			forn(i, 0, k - 1) {
				string temp;
				cin >> temp;
				if (temp[0] == '!') {
					int cur = dict[temp.substr(1)];
					if (!cur) cur = NEGMAX;
					maxf = min(maxf, cur);
				} else {
					if (!dict[temp]) can = false;
					maxp = max(maxp, dict[temp]);
				}
				if (maxp >= maxf) can = false;
			}
			if (!can) cout << "Plot Error\n";
			else if (maxf == NEGMAX) cout << "Yes\n";
			else cout << (int) e.size() - maxf + 1 << " Just A Dream\n";
		}
	}
	return 0;
}
