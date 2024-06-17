/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
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
const int maxn = 1e5 + 3;
const int maxk = 1e2 + 3;
vi go[maxk], g[maxn];
int ans[maxn][maxk];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m, k, s;
	cin>>n>>m>>k>>s;
	forn(i,0,n-1) {
		int t;
		cin>>t;t--;
		go[t].pb(i);
	}
	forn(i,0,m-1){
		int a,b;
		cin>>a>>b;a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i,0,k-1) {
		vi dist(n, INF);
		queue<int> q;
		for (auto &c : go[i]) {
			dist[c] = 0;
			q.push(c);
		}
		while(!q.empty()) {
			int p=q.front();q.pop();
			for(auto &n:g[p]) {
				if(dist[n]<=dist[p]+1) continue;
				dist[n]=dist[p]+1;
				q.push(n);
			}
		}
		forn(j,0,n-1) ans[j][i]=dist[j];
	}
	forn(i,0,n-1) {
		sort(ans[i], ans[i] + k);
		int t=0;
		// forn(j,0,k-1) cout << ans[i][j] << ' ';
		// cout<<'\n';
		forn(j,0,s-1) t+=ans[i][j];
		cout<<t<<' ';
	}
	cout<<'\n';
	return 0;
}
