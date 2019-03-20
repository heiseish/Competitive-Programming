/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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


const int maxn = 1e5 + 3;
ll EulerPhi[maxn];
void precomputeEulerPhi() {
	for(int i = 1; i <= maxn - 1; ++i) EulerPhi[i] = i;
	for(int i = 2; i <= maxn - 1; ++i) 
		if (EulerPhi[i] == i)
			for(int j = i; j <= maxn - 1; j += i)
				EulerPhi[j] = (EulerPhi[j]/i) * (i - 1);
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	precomputeEulerPhi();
	while(tc--) {
		int k, n;
		cin>>k>>n;
		cout << k << ' ';
		ll ans = 2;
		forn(i,2,n) ans += EulerPhi[i];
		cout << ans <<'\n';
	}
	return 0;
}
