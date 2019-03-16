/** 
Those who cannot acknowledge themselves will eventually fail.        
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
	ll k;
	cin>>n>>k;
	vi a(n);
	forn(i,0,n-1)cin>>a[i];
	if (k >= n) cout << *max_element(all(a)) <<'\n';
	else {
		deque<int> d;
		for(auto &v : a) d.pb(v);
		int a=d.front();d.pop_front();
		int b=d.front();d.pop_front();
		int as=0,bs=0;
		while(true) {
			if(a>b) {
				as++;
				bs=0;
				d.pb(b);
				b=d.front();d.pop_front();
			} else {
				bs++;
				as=0;
				d.pb(a);
				a=d.front();d.pop_front();
			}
			if(as == k) {
				cout<<a<<'\n';
				return 0;
			} 
			if(bs==k) {
				cout<<b<<'\n';
				return 0;
			}
		}

	}
	return 0;
}
