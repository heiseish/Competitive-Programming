/** 
It does not do to dwell on dreams and forget to live.        
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
#define DFS_WHITE -1 // normal DFS, do not change this with other values (other than 0), because we usually use memset with conjunction with DFS_WHITE
#define DFS_BLACK 1
int n, m, d;
const int MAX_N = 1e5 + 3;
unordered_map<string, vector<string> > g;
unordered_map<string, int> check;
unordered_map<string, int> no;
unordered_map<string, int> dfs_num;
int currank = 1;
vector<string> topoSort;

void dfs2(string u) {    // change function name to differentiate with original dfs
  dfs_num[u] = DFS_BLACK;
  for (auto &v : g[u])
    if (dfs_num[v] == DFS_WHITE)
      dfs2(v);
  topoSort.push_back(u); }                   // that is, this is the only change


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> d;
    string temp = "";
    forn(i, 0, m - 1) {
        string a, b;
        cin >> a >> b;
        g[a].pb(b);
        check[a]++;
        check[b]++;
    }

	for (auto &v : check)            // this part is the same as finding CCs
		dfs_num[v.st] = DFS_WHITE;

	for (auto &v : check)            // this part is the same as finding CCs
		if (dfs_num[v.st] == DFS_WHITE)
		dfs2(v.st);
	reverse(topoSort.begin(), topoSort.end());                 // reverse topoSort
	for (int i = 0; i < (int)topoSort.size(); i++)       // or you can simply read
		no[topoSort[i]] = i + 1;          // the content of `topoSort' backwards

    vi ranklist;
    forn(i, 1, n) {
        string cur;
        cin >> cur;
        if (check[cur]) 
			ranklist.pb(no[cur]);
    }
    int L[MAX_N], L_id[MAX_N], P[MAX_N];

    int lis = 0, lis_end = 0;
    for (int i = 0; i < (int) ranklist.size(); ++i) {
        int pos = lower_bound(L, L+lis, ranklist[i]) - L;
        L[pos] = ranklist[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos-1] : -1;
        if (pos+1 > lis) {
            lis = pos+1;
            lis_end = i;
        }
    }
    kakimasu((n - lis) * 2);
    return 0;
}