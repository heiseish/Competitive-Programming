/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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

struct Set {
	priority_queue<Set> children;
	bool operator==(const Set& rhs) const {
		if (sz(children) != sz(rhs.children)) {
			return false;
		}
		forn(i, 0, sz(children) - 1) {
			if (children[0] != rhs.children[0]) 
				return false;
		}
		return true;
	}

	bool operator<(const Set& rhs) const {
		if (sz(children) != sz(rhs.children)) {
			return false;
		}
		forn(i, 0, sz(children) - 1) {
			if (children[0] != rhs.children[0]) 
				return false;
		}
		return true;
	}
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		int op;
		cin>>op;
		stack<Set> s;
		while(op--) {
			string c;
			cin>>c;
			if (c=="PUSH") {
				Set temp;
				s.push(temp);
			} else if (c=="DUP") {
				Set temp = s.top();
				s.push(temp);
			} else if (c=="UNION") {

			}
		}
	}
	return 0;
}
