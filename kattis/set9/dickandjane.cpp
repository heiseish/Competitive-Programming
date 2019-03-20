/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	ll s, p, y, j;
	while(cin>>s>>p>>y>>j) {
		ll dj = 12 + j;
		ll c = dj - y - p;
		c/=3;
		ll a = c + y;
		ll b = c + p;
		if (a + b + c == dj) {}
		else if (a + b + c == dj - 1) {
			if (a == b + s) a++;
			else b++;
		} else if (a + b + c == dj - 2) {
			a++;
			b++;
		} else {
			assert(1 == 0);
		}
		cout << a << ' ' << b  << ' ' << c <<'\n';
	}
	return 0;
}
