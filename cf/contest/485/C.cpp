/** 
It does not do to dwell on dreams and forget to live.        
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
	vpi a(n);
	forn(i,0,n-1)cin>>a[i].st;
	forn(i,0,n-1)cin>>a[i].nd;
	vi b(n, INF);
	forn(i,1,n-1) {
		forn(j,0,i-1) {
			if (a[j].st < a[i].st) {
				b[i]=min(b[i], a[i].nd + a[j].nd);
			}
		}
	}
	int ans=INF;
	forn(i,1,n-1) {
		forn(j, 0, i-1) {
			if (a[j].st < a[i].st) {
				ans=min(ans, b[j] + a[i].nd);
			}
		}
	}
	cout << (ans==INF?-1:ans)<<'\n';
	return 0;
}
