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

int fac[11];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	fac[0] = 1;
	forn(i, 1, 10) {
		fac[i] = fac[i-1]*i;
	}
	while(tc--) {
		int n;
		cin >> n;
		cout << fac[n]%10 <<'\n';
	}
	return 0;
}
