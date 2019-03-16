/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
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
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	double f = 1.0 * ((b1 + a1) / 2.0 + (b2 + a2) / 2.0);
	cin >> a1 >> b1 >> a2 >> b2;
	double s = 1.0 * ((b1 + a1) / 2.0 + (b2 + a2) / 2.0);
	if (f > s) cout << "Gunnar\n";
	else if (f==s) cout << "Tie\n";
	else cout << "Emma\n";
	return 0;
}
