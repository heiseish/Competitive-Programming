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
vi ar;
vi sum;

void lap(int mask) {
	int s = 0, id = 0;
	while(mask) {
		if (mask & 1) {
			s+=ar[id];
		}
		id++;
		mask>>=1;
	}
	sum.pb(s);
}

const int maxnp = 200;
const int maxm = 1 << 14;
int dp[maxm][maxnp];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	forn(i,1,n) {
		int a;
		cin>>a;
		ar.pb(a);
	}
	forn(i,1,(1 << n) - 1) lap(i);
	sort(all(sum));
	UNIQUE(sum);

	return 0;
}
