/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
const int maxn = 1e5 + 3;
int vis[maxn];
vi topoSort;             // global vector to store the toposort in reverse order
unordered_map<int, vi> g;
unordered_map<string, int> sti;
unordered_map<int, string> its;

int ct=0;
void dfs(int u) {    // change function name to differentiate with original dfs
  for (auto &v : g[u])
    if (!vis[v]++)
      dfs(v);
  topoSort.push_back(u); 
}                   // that is, this is the only change


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	cin.ignore();
	forn(i,0,n-1) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string t;
		ss>>t;
		t.pop_back();
		int source;
		if (sti.find(t) == sti.end()) {
			source = ct;
			sti[t]=ct++;
			its[source]=t;
		} else source = sti[t];
		string dep;
		while(ss>>dep) {
			int tar;
			if (sti.find(dep) == sti.end()) {
				tar=ct;
				sti[dep]=ct++;
				its[tar]=dep;
			} else tar=sti[dep];
			g[tar].pb(source);
		}
	}
	string start;
	cin>>start;
	dfs(sti[start]);
	for(int i=sz(topoSort)-1;i>=0;i--)cout<<its[topoSort[i]]<<'\n';
	return 0;
}
