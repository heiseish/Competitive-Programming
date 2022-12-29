/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
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
	int m;
	while(true) {
		cin >> m;
		if (!m) break;
		int curw = 0, curh = 0;
		int totalw = 0, totalh = 0;
		while(true) {
			int a, b;
			cin >> a >> b;
			if (a == -1 && b == -1) break;
			if (a > m - curw) {
				totalh += curh;
				totalw = max(totalw, curw);
				curw = a;
				curh = b;
			} else {
				curw += a;
				curh = max(b, curh);
			}
		}
		totalh += curh;
		totalw = max(totalw, curw);
		cout << totalw << " x " << totalh << '\n';
	}
	return 0;
}
