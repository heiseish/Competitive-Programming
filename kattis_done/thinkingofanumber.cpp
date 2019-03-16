/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
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

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(scanf("%d", &n) && n) {
		vi d;
		int ma = 5e4 + 1, mi = 1;
		forn(i, 1, n) {
			string c1, c2;
			int num;
			cin >> c1 >> c2 >> num;
			if (c1 == "greater") mi = max(mi, num + 1);
			else if (c1 == "less") ma = min(ma, num - 1);
			else d.pb(num);
		}
		if (ma == 5e4 + 1) printf("infinite\n");
		else {
			vi ans;
			forn(i, mi, ma) {
				int can = true;
				for (auto &v : d) 
					if (i%v!=0) can = false;
				if (can) ans.pb(i);
			}
			if (ans.empty()) printf("none");
			else {
				for (auto &v : ans) printf("%d ", v);
			}	
			printf("\n");
		}
	}
	return 0;
}
