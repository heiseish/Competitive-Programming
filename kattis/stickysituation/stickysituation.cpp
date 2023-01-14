/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vll d(n);
	forn(i, 0, n - 1) cin >> d[i];
	sort(all(d));
	forn(std, 0, n - 3) {
		if (d[std] + d[std + 1] > d[std + 2] && d[std + 1] + d[std + 2] > d[std]
		&& d[std + 2] + d[std] > d[std + 1]) {
			cout << "possible\n";
			exit(0);
		}
			
	}
	cout << "impossible\n";
	return 0;
}
