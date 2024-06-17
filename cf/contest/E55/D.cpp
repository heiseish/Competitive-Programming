/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 5e2 + 3;
int gr[maxn], explored[maxn] = { 0 };
vpi res;
int gc;
unordered_map<int, vi> graph;

int find(int index) {
	if (gr[index] == index) return index;
	return gr[index] = find(gr[index]);
}

void join(int a, int b, vi& ma) {
	int ga = find(a);
	int gb = find(b);
	if (ga == gb) return;
	gc--;
	gr[ga] = gb;
	ma[a]--;
	ma[b]--;
	res.pb({a, b});
}

int maxdia = -1;
int BFS(int index) {
	unordered_map<int, int> localRecordMap;
	queue<int> q;
	q.push(index);
	int MAX = 0;
	int indexMax = 0;
	while (!q.empty()) {
		int temp = q.front();
		explored[temp] = 1;
		q.pop();
		for (auto i : graph[temp]) {
			if (!explored[i]) {
				localRecordMap[i] = localRecordMap[temp] + 1;
				if (localRecordMap[i] > MAX) {
					MAX = localRecordMap[i];
					indexMax = i;
				}
				q.push(i);
			}
		}
	}
	if (MAX > maxdia) maxdia = MAX;
	return indexMax;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	gc = n;
	vi ma(n + 1);
	int total;
	vi g;
	forn(i, 1, n) {
		scanf("%d", &ma[i]);
		total+=ma[i];
		gr[i] = i;
		g.pb(i);
	}
	if (total < 2 * n - 2) {
		printf("NO\n");
		exit(0);
	}
	while(gc > 1) {
		
		sort(all(g), [ma]( const auto& lhs, const auto& rhs ){
			return ma[lhs]< ma[rhs];
		});
		int f = 0, s = g.size() - 1;
		while(ma[g[f]] == 0) f++;
		while(find(g[f]) == find(g[s])) s--;
		join(g[f], g[s], ma);
	}
	for (auto i : res) {
		graph[i.st].pb(i.nd);
		graph[i.nd].pb(i.st);
	}
	int ee = BFS(1);
	memset(explored, 0, sizeof explored);
	BFS(ee);
	printf("YES %d\n", maxdia);
	printf("%d\n", (int) res.size());
	for (auto i : res) printf("%d %d\n", i.st, i.nd);
	return 0;
}
