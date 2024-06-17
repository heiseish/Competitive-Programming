/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin>>n>>m;
	vi d(m);
	unordered_map<int, vi> track;
	forn(i,0,m-1){
		cin>>d[i];
		track[d[i]].pb(i);
	}
	int iter=INF;
	if (sz(track)<n) {
		forn(i,0,m-1) cout<<'0';
		cout<<'\n';
		exit(0);
	}
	for (auto &v:track)iter=min(iter,sz(v.nd));
	vi marked(m,0);
	int cur=0;
	forn(i,0,iter-1){
		int ans=0;
		for(auto &v : track)
			ans=max(ans,v.nd[i]);
		marked[ans]++;
	}
	for(auto &i:marked)cout<<i;
	cout<<'\n';

	return 0;
}
