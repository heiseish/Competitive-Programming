/** 
When a man learns to love, he must bear the risk of hatred.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x

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
const int maxn = 1e2 + 2;
int o[maxn][maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true) {
		int w, h, n;
		cin >> w >>h >> n;
		if (cin.eof()) break;
		memset(o, 0, sizeof o);
		map<int, string> id;
		int cur = 1;
		forn(i, 0, n - 1) {
			string name;
			cin >> name;
			id[cur++]=name;
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			forn(i, x1, x2 - 1) forn(j,y1,y2 - 1) {
				if (o[i][j] == 0) o[i][j] = cur-1;
				else o[i][j] = -1;
			}
		}
		cout << "Total " << w * h << '\n';
		int unallo = 0;
		unordered_map<string, int> allo;
		int cted = 0;
		forn(i, 0, w - 1) forn(j, 0, h - 1) {
			if (o[i][j] == -1) cted++;
			else if (o[i][j] == 0) unallo++;
			else allo[id[o[i][j]]]++;
		}
		cout << "Unallocated " << unallo << '\n';
		cout << "Contested " << cted << '\n';
		for (auto &name : id) {
			cout << name.nd << ' ' << allo[name.nd] << '\n';
		}
	}
	return 0;
}
