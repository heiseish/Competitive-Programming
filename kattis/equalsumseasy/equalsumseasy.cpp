/** 
Wherever someone is still thinking of you, that place is your home.        
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
const int maxn = 21;
int a[maxn];
int get(int i) {
	int id = 0, ret = 0;
	while (i) {
		if (i & 1) ret += a[id];
		i>>=1;
		id++;
	}
	return ret;
}

void print(int i) {
	int id = 0, ret = 0;
	while (i) {
		if (i & 1) cout << a[id] <<' ';
		i>>=1;
		id++;
	}
	cout <<'\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int TC;
	cin>>TC;
	forn(tc,1,TC) {
		int n;
		cin >> n;
		forn(i,0,n-1) cin>>a[i];
		unordered_map<int, int> g;
		bool can = false;
		cout << "Case #" << tc << ":\n";
		forn(i,0,(1 << n) - 1) {
			int s = get(i);
			if (g.count(s)) {
				print(g[s]);
				print(i);
				can = true;
				break;
			} else {
				g[s] = i;
			}
		}
		if (!can) cout << "Impossible\n";
	}
	return 0;
}
