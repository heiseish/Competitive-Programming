/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
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
	string n;
	cin >> n;
	vector<char> ans;
	deque<char> p;
	bool front;
	if (n.length()%2==0) front = false;
	else front = true;
	for (auto &v : n) p.pb(v);
	while(!p.empty()) {
		char ch;
		if (front) {
			ch = p.front();
			p.pop_front();
		} else {
			ch = p.back();
			p.pop_back();
		}
		front = !front;
		ans.pb(ch);
	}
	for (int i = (int) ans.size() - 1; i >= 0; i--) cout << ans[i];
	cout << '\n';
	return 0;
}
