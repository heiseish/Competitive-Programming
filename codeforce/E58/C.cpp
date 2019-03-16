/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?        
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
unordered_map<int, vi> g;
vi colors;
bool can = true;
void dfs(int index) {
	if(!can) return;
	for (auto &v:g[index]) {
		if(!can) return;
		if (colors[v]==-1) {
			colors[v] = 1-colors[index];
			dfs(v);
		} else if (colors[v]==colors[index]) can = false;	
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		g.clear();
		cin>>n;
		vector<pair<pi, int> > v(n);
		colors.assign(n,-1);
		can = true;
		forn(i,0,n-1){
			cin>>v[i].st.st>>v[i].st.nd;
			v[i].nd=i;
		}
		sort(all(v));
		vector<vi> s;
		vector<bool> check(n, false);
		forn(i,0,n-1){
			if (check[i]) continue;
			vi temp;
			temp.pb(v[i].nd);
			check[i]= true;
			int r=v[i].st.nd;
			forn(j,i+1,n-1){
				if (check[j]) continue;
				if(v[j].st.st<=r) {
					temp.pb(v[j].nd);
					check[j]=true;
					r=max(r, v[j].st.nd);
				}
			}
			s.pb(temp);
		}
		if (sz(s)==1) cout << "-1\n";
		else {
			vi ans(n, 0);
			for (auto &v : s[0]) {
				ans[v] = 1;
			}
			forn(i,1,sz(s)-1){
				for (auto &v:s[i]) {
					ans[v]=2;
				}
			}
			for (auto &v:ans) cout << v << ' ';
			cout <<'\n';
		}
	}
	return 0;
}
