/** 
People become stronger because they have things they cannot forget. That’s what you call growth.        
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
const int maxn = 5e4 + 3;
int f[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	forn(i,2,(int)5e4) f[i] = i * (i + 1) / 2;
	while(tc--) {
		int n;
		cin>>n;
		int last = upper_bound(f+1, f + (int)5e4, n) - (f + 1);
		bool can = false;
		forn(i,2,last) {
			if ((n - f[i])%i == 0) {
				can = true;
				int toadd = (n - f[i])/i;
				cout << n << " = ";
				forn(j,1,i-1) cout << j + toadd << " + ";
				cout << toadd + i <<'\n';
				break;
			}
		}
		if (!can) cout << "IMPOSSIBLE\n";

	}
	return 0;
}
