/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.        
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
	string s;
	cin >> s;
	int l = s.length();
	int r = sqrt(l);
	while(l%r!=0) r--;
	int c = l/r;
	vector<vector<char> > b(r, vector<char> (c, 'a'));
	int cur = 0;
	forn(j, 0, c - 1)
		forn(i, 0, r - 1)
			b[i][j] = s[cur++];
	forn(i, 0, r - 1)
		forn(j, 0, c - 1)
			cout << b[i][j];
	cout << '\n';
	
	return 0;
}
