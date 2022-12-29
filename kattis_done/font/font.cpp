/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
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
int ans = 0;
const int done = (1 << 26) - 1;
vi g(1 << 26);
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	forn(i,0,n-1) {
		string s;
		cin>>s;
		int ret = 0;
		for (auto &ch : s) ret |= (1 << (int) (ch - 'a'));
		g[1 << i] = ret;
	}
	forn(i,0,(1<<n)-1) {
		int pos = i;
		int can = 0;
		while(pos) {
			int p = pos & -pos;
			can |= g[p];
			pos -= p;
			if (can == done) break;
		}
		if (can == done) ans++;
	}
	cout << ans <<"\n";
	return 0;
}
