/** 
Justice isn’t something that you can just proclaim. It’s a feeling you should keep near your heart.        
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
	int n, q;
	cin>>n>>q;
	vi d(n+3, 0);
	int s=(int)floor(sqrt(1.0*n));
	vvi g(s+4, vi(s+4, 0));
	while(q--) {
		int qn;
		cin>>qn;
		if (qn == 1) {
			int a, b, c;
			cin>>a>>b>>c;
			if (b<=s) g[b][a]+=c;
			else {
				for(int j = a;j<=n;j+=b) {
					d[j]+=c;
				}
			}
		} else {
			int idx;
			cin>>idx;
			int ans = d[idx];
			for(int i = 1; i <= s;i++) ans+=g[i][idx%i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
