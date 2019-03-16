/** 
it is foolish to fear what we have to see and know”        
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
	string s;
	cin>>s;
	int ans = 0;
	forn(i,1,sz(s)-2) {
		if (s[i] == 'A') {
			int l = 0, r= 0;
			forn(j,0,i-1) if(s[j]=='Q') l++;
			forn(j,i+1,sz(s)-1) if(s[j]=='Q') r++;
			ans += l * r;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
