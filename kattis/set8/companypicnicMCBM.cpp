/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
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


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }
  
  VD dist(n);
  VI dad(n);
  VI seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
	if (dist[k] > new_dist) {
	  dist[k] = new_dist;
	  dad[k] = j;
	}
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}

map<string, double> speed;
map<string, int> clr, vis, mapping;
map<int, string> rmapping;
int ct = 1;
map<string, vector<string> > g;
string root;

void dfs(string idx, int color) {
	clr[idx] = color;
	for (auto &s : g[idx]) {
		if (!vis[s]++) dfs(s, color^1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int N;
	cin>>N;
	
	forn(i,1,N) {
		string e, s;
		double sp;
		cin>>e>>sp>>s;
		if (s == "CEO") root = e;
		else g[s].pb(e);
		speed[e] = sp;
	}
	dfs(root, 0);

	for (auto &v : clr)
		if (v.nd == 0) {
			mapping[v.st] = ct;
			rmapping[ct++] = v.st;
		}
	// n = ct - 1;
	for (auto &v : clr)
		if (v.nd == 1) {
			mapping[v.st] = ct;
			rmapping[ct++] = v.st;
		}
	// m = ct - n - 1;
	vector<VD> cost(N+1, VD(N+1, 0));
	for (auto &v : g) {
		for (auto &n : v.nd) {
			int i = mapping[v.st], j = mapping[n];
			double ss = min(speed[v.st], speed[n]);
			if (i < j) cost[i][j] = -ss;
			else cost[j][i] = -ss;
		}
	}
	VI left, right;
	double ans = -1.0 * MinCostMatching(cost, left, right);
	int pair = 0;
	forn(i,1,N) {
		if (left[i] == -1 || cost[i][left[i]] == 0) continue;
		pair++;
	}
		
	cout << pair << ' ';
	cout << setprecision(15) <<  ans / pair <<'\n';


	return 0;
}
