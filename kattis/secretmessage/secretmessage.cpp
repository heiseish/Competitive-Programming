/** 
The only ones who can miss a kick draw are those who have the courage to kick it.        
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
		string s;
		cin >> s;
		int l = s.length();
		int sl = sqrt(l);
		while(sl * sl < l) sl++;
		vector<vector<char> > b(sl, vector<char> (sl, 'a'));
		int cur = 0;
		forn(i, 0, sl - 1)
			forn(j, 0, sl - 1) 
				b[i][j] = cur < s.length() ? s[cur++] : '*';
		forn(j, 0, sl - 1)
			for (int i = sl - 1; i >= 0; i--)
				if (b[i][j] != '*') cout << b[i][j];
		cout << '\n';
	}
	return 0;
}
