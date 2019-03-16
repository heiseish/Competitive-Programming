/** 
Those who cannot acknowledge themselves will eventually fail.        
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
	int n1, n2;
	cin >> n1 >> n2;
	string f, s;
	cin >> f >> s;
	int t;
	cin >> t;
	reverse(all(f));
	f += s;
	vector<int> order(n1 + n2, 1);
	forn(i, n1, n1 + n2 - 1) order[i] = 2;
	while(t--) {
		forn(i, 0, n1 + n2 - 2) {
			if (order[i] == 1 && order[i + 1] == 2) {
				swap(order[i], order[i + 1]);
				swap(f[i], f[i + 1]);
				i++;
			}
		}
	}
	cout << f << '\n';
	return 0;
}
