/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
const int maxn = 1e5 + 6;
int a[maxn], b[maxn], c[maxn];
vi aa[maxn], bb[maxn], cc[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	forn(i,1,n) {
		cin >> a[i];
		aa[a[i]].pb(i);
	}
	forn(i,1,n) {
		cin >> b[i];
		bb[b[i]].pb(i);
	}
	forn(i,1,n) {
		cin >> c[i];
		cc[c[i]].pb(i);
	}
	vi toRemoveA, toRemoveBC;
	forn(i,1,n) {
		if (bb[i].empty() || cc[i].empty()) toRemoveA.pb(i);
	}
	while(!toRemoveA.empty()) {
		int k = toRemoveA.back(); toRemoveA.pop_back();
		int col = aa[k];
		toRemoveBC.pb(a[col]);
	}
	return 0;
}
