/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
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
vector<vi> g;
vi in, out;
int n, m;
void solve(int st) { 
    unordered_map<int,int> e; 
    forn(i,0, n-1) e[i] = sz(g[i]);
    stack<int> ans; 
    vector<int> c; 
    ans.push(st); 
    int cur = st;
    while (!ans.empty()) { 
        if (e[cur]) { 
			ans.push(cur); 
			int next_v = g[cur].back(); 
            e[cur]--; 
            g[cur].pop_back(); 
            cur = next_v; 
        } else{ 
			c.push_back(cur); 
            cur = ans.top();
            ans.pop(); 
        } 
    } 

	if (sz(c) != m + 1) cout << "Impossible";
	else for (int i=sz(c)-1; i>=0; i--)
        cout << c[i] << ' '; 
	cout << '\n';
} 


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	while(cin>>n>>m && (n||m)) {
		g.assign(n, {});
		in.assign(n, 0);
		out.assign(n, 0);
		int st =0, en =n-1;
		int a, b;
		forn(i, 1, m) {
			cin>>a>>b;
			out[a]++;
			in[b]++;
			g[a].pb(b);
		}
		bool can = true;
		int numIn = 0, numOut = 0;
		int hasSt = 0, hasEn = 0;
		forn(i, 0, n-1) {
			if (in[i]-out[i] == 1) {
				en = i;
				numOut++;
				hasEn=1;
			} else if (out[i]-in[i] == 1) {
				st = i;
				numIn++;
				hasSt=1;
			} else if (out[i] != in[i]) can = false;
		}
		if (numIn > 1 || numOut > 1) can = false;
		if (!can) cout << "Impossible\n";
		else solve(st);
	}
	return 0;
}
