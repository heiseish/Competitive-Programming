/** 
Those who do not understand true pain can never understand true peace.        
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
		int n;
		string s;
		cin >> n >> s;
		deque<char> l;
		for (auto &ch : s) l.pb(ch);
		bool front  = true;
		while(n-- && l.size() >= 4) {
			int cl = l.size();
			forn(i, 1, cl/4) {
				if (front) l.pop_front();
				else l.pop_back();
			}
			front = !front;
		}
		for (auto &ch : l) cout << ch;
		cout << '\n';
	}
	return 0;
}
