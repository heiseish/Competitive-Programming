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

bool solve(int a, int b, bool player) {
	if (a%b == 0) return player;
	int s = a / b;
	s*=b;
	while(s > 0) {
		int nexta = max(a - s, b);
		int nextb = min(a - s, b);
		bool can = solve(nexta, nextb, !player);
		if (can == player) return player;
		s-=b;
	}
	return !player;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b;
	while(true) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		if (a < b) swap(a, b);
		cout <<  (solve(a, b, false) ? "Ollie wins" : "Stan wins") << '\n';
	}
	return 0;
}
