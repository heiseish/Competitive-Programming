/** 
it is foolish to fear what we have to see and know”        
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

const int INF = 1 << 26;
/**
Start coding from here
*/
int in[26], out[26];
vector<string> gr[26][26];
vector<string> d[26];
vi g[26];
int n;
vector<string> dict;
int toInt(char ch) {
	return ch - 'a';
}
void hierholzer(int stx) { 
    vi e(26);
    forn(i,0, 25) e[i] = sz(g[i]);
    stack<int> ans; 
    vector<int> c; 
    ans.push(stx); 
    int cur = stx;
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

	if (sz(c) != n + 1) cout << "***";
	else 
	for (int i=sz(c)-1; i>=1; i--) {
		if (i != sz(c) - 1) cout<<'.';
		cout << gr[c[i]][c[i-1]].back();
		gr[c[i]][c[i-1]].pop_back();
	}
	cout << '\n';
} 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    cin>>tc;
    while(tc--) {
        cin>>n;
        dict.resize(n);
		
		forn(i, 0, 25) {
			g[i].clear();
			d[i].clear();
			forn(j, 0, 25) gr[i][j].clear();
		}
		memset(in, 0, sizeof in);
		memset(out, 0, sizeof out);
        forn(i, 0, n-1) {
			cin>>dict[i];
			int inn = toInt(dict[i].front());
			int outt = toInt(dict[i].back());
			in[outt]++;
			out[inn]++;
			// g[inn].pb(outt);
			d[inn].pb(dict[i]);
		}
		forn(i, 0, 25) {
			vector<string> &tmp = d[i];
			sort(all(tmp), greater<string>());
			for (auto &v : tmp) g[i].pb(toInt(v.back()));
		}
		sort(all(dict), greater<string>());
		for (auto &s : dict) {
			gr[toInt(s.front())][toInt(s.back())].pb(s);
		}
		bool can = true;
		int numIn = 0, numOut = 0;
		int hasSt = 0, hasEn = 0;
		int stx = 0;
		forn(i, 0, 25) {
			if (in[i]-out[i] == 1) {
				numOut++;
				hasEn=1;
			} else if (out[i]-in[i] == 1) {
				stx = i;
				numIn++;
				hasSt=1;
			} else if (out[i] != in[i]) can = false;
		}
		if (numIn > 1 || numOut > 1) can = false;
		if (!can) {
			cout << "***\n";
			continue;
		}
		// forn(i, 0, 25) {
		// 	sort(all(g[i]), greater<int>());
		// }

        if (!hasSt && !hasEn)
			while(out[stx] + in[stx] == 0) stx++;
		hierholzer(stx);
    }
    return 0;
}
