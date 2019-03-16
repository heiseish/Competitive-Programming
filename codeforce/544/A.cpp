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

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int h1,m1,h2,m2;
	scanf("%d:%d", &h1, &m1);
	scanf("%d:%d", &h2, &m2);
	int dur = h2 * 60 + m2 - h1 * 60 - m1;
	dur/=2;
	int tmid = h1 * 60 + m1 + dur;
	printf("%02d:%02d\n",tmid/60, tmid%60);
	return 0;
}
