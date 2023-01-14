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
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	while(tc--) {
		string em;
		cin >> em;
		int ss = sqrt(em.length());
		int cur = 0;
		vector<vector<char> > b(ss, vector<char> (ss, 'a'));
		forn(i, 0, ss - 1)
			forn(j, 0, ss - 1) {
				b[i][j] = em[cur++];
			}
		for (int j = ss - 1; j >= 0; j--) {
			for (int i = 0; i < ss; i++) {
				cout << b[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}
