/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
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
	int m;
	cin>>m;
	vi a(m);
	forn(i,0,m-1) cin>>a[i];
	sort(all(a));
	vi ans;
	bool can = true;
	forn(i, 1, m-1) {
		if(a[i]%a[0]!=0) can = false;
	}
	if (!can) puts("-1");
	else {
		cout << 2 * m - 1<<'\n';
		forn(i,0,m-2) {
			cout << a[i] << ' ' <<  a[0] << ' ';
		}
		cout << a.back();
		cout<<'\n';
	}
	return 0;
}
