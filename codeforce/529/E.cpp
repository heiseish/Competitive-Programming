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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	stack<char> cur;
	int ans = 0;
	forn(i, 0, n - 1) {
		char n = getchar();
		if (n == ')') {
			if (cur.empty()) {
				ans++;
				cur.push('(');
			} else {
				char c = cur.top();
				if (c != '(') ans++;
				cur.pop();
			}
		} else {
			cur.push(n);
		}
	}
	if (cur.size()%2==1) {
		puts("0");
	} else {
		cout << ans + cur.size()/2 << '\n';
	}
	return 0;
}
