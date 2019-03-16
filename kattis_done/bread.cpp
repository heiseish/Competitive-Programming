/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi a(n), b(n);
	vi oa(n), ob(n);
	forn(i,0,n-1) {
		cin>>a[i];
		oa[a[i]] = i;
	}
	forn(i,0,n-1) {
		cin>>b[i];
		ob[b[i]] = i;
	}
	forn(i,1,n-2) {
		int f = ob[a[i-1]];
		int m = ob[a[i]];
		int s = ob[a[i+1]];
		if (m > f && m < s) continue;
		if (f > s && f < m) continue;
		if (s > m && s < f) continue;
		if ((m == s + 1 && f == m + 1) || (f == m + 1 && s == f + 1) || (s == f + 1 && m == s + 1)) {
			cout << "Impossible\n";
			debug(i);
			return 0;

		}
			
		
	}
	cout << "Possible" <<'\n';
	return 0;
}
