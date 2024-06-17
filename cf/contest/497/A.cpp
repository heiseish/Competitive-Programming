/** 
People who continue to put their lives on the line to defend their faith become heroes and continue to exist on in legend.        
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
	vector<bool> c(n, false);
	forn(i,0,n-1) {
		cin>>a[i];
		b[i]=a[i];
	}
	sort(all(b));
	int ans = 0;
	forn(i,0,n-1) {
		int idx = upper_bound(all(b), a[i]) - b.begin();
		while(idx < n && c[idx]) idx++;
		if (idx < n && b[idx] > a[i]) {
			ans++;
			c[idx]=true;
		}
	}
	cout<< ans<<'\n';
	return 0;
}
