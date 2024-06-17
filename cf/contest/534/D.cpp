/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
char ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	char n;
	cin >> n;
	return n;
}
void declare(int x) {
	cout << "! " << x<< endl;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// #ifdef LOCAL_PROJECT
	// 	freopen("input.txt","r",stdin);
	// #endif
	string s;
	char ans;
	while(cin>>s) {
		if (s=="mistake" || s=="end") break;
		int l = 0, r = 1;
		char k;
		ans = ask(l, r);
		if (ans != 'x')
			forn(i, 0, 29) {
				l = 1<<i;
				r = 1<< (i + 1);
				ans = ask(l, r);
				if (ans == 'x') break;
			}
		while(l+1<r) {
			int mid = (l+r)>>1;\
			k = ask(l, mid);
			if (k == 'y') l = mid;
			else r = mid; 
		}
		declare(r);
	}
	return 0;
}