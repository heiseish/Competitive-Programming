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
const int maxc = 2e5 + 3;
vi g[maxc];
int in[maxc], n[maxc], gone[maxc];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int c, p, x, l;
	cin>>c>>p>>x>>l;
	forn(i,1,p) {
		int a, b;
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
		n[a]++;
		in[a]++;
		n[b]++;
		in[b]++;
	}
	queue<int> stupid;
	stupid.push(l);
	while(!stupid.empty()) {
		int ff = stupid.front(); stupid.pop();
		if (gone[ff]) continue;
		gone[ff]++;
		if (ff == x) {
			cout << "leave\n";
			return 0;
		}
		for (auto &v : g[ff]) {
			if (gone[v]) continue;
			n[v]--;
			if (n[v] <= in[v]/2) stupid.push(v);
		}
	}
	cout << "stay\n";
	return 0;
}
