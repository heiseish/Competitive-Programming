/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<vector<pair<pi, int> > > board(1001);
	forn(i,1,n) {
		int a, b;
		cin>>a>>b;
		int k=a/1000;
		board[k].pb({{a, b}, i});
	}
	int k = 0;
	forn(i, 0, 1000) {
		if (k==n) break;
		k+=sz(board[i]);

		if (i%2==0) 
			sort(all(board[i]), [](pair<pi, int> &lhs, pair<pi, int> &rhs) {
				return lhs.st.nd > rhs.st.nd;
			});
		else
			sort(all(board[i]), [](pair<pi, int> &lhs, pair<pi, int> &rhs) {
				return lhs.st.nd < rhs.st.nd;
			});
		for (auto &s : board[i]) {
			cout << s.nd << ' ';
		}
	}
	cout <<'\n';
	return 0;
}
