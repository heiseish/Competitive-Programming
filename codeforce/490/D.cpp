/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
	int n, m;
	cin>>n>>m;
	vi a(n);
	deque<pi> ans;
	forn(i,0,n-1){
		cin>>a[i];
		ans.pb({a[i]%m, i});
	}
	sort(all(ans));
	vpi can;
	forn(i, 0, m-1) {
		forn(j, 1, n/m) {
			if (ans.front().st == i) {
				can.pb({ 0, ans.front().nd });
				ans.pop_front();
			} else if (ans.front().st > i) {
				can.pb({ i + m - ans.back().st, ans.back().nd });
				ans.pop_back();
			} else {
				can.pb({ i - ans.front().st, ans.front().nd });
				ans.pop_front();
			}
		}
	}
	ll moves=0LL;
	for (auto &v : can) {
		a[v.nd]+=v.st;
		moves+=v.st;
	}
	cout<<moves<<'\n';
	forn(i,0,sz(a)-1) {
		if (i>0)cout<< ' ';
		cout<<a[i];
	}
	cout<<'\n';

	return 0;
}
