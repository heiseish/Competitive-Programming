/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
const int MAX_N = 62500 + 3;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin >> tc;
	int cas = 1;
	while(tc--) {
		int n, p, q;
		cin >> n >> p >> q;
		vi pm(p + 1);
		forn(i, 0, p) cin >> pm[i];
		vi pf(q + 1);
		forn(i, 0, q) cin >> pf[i];
		unordered_map<int, int> newOrd;
		forn(i, 0, q) newOrd[pf[i]] = i;
		forn(i, 0, p) pm[i] = newOrd[pm[i]];
		int L[MAX_N], L_id[MAX_N], P[MAX_N];

		int lis = 0, lis_end = 0;
		for (int i = 0; i <= p; ++i) {
			int pos = lower_bound(L, L+lis, pm[i]) - L;
			L[pos] = pm[i];
			L_id[pos] = i;
			P[i] = pos ? L_id[pos-1] : -1;
			if (pos+1 > lis) {
				lis = pos+1;
				lis_end = i;
			}
		}

		cout << "Case " << cas++ << ": " << lis << '\n';

	}
	return 0;
}
