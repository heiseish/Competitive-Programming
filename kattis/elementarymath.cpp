/** 
People become stronger because they have things they cannot forget. That’s what you call growth.        
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
#define MAX 200003
#define NIL 0

vector<int> G[MAX];
int n, m;
vi match, dist;
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]
bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int N;
	cin>>N;
	vpll a(N+1);
	map<ll, int> mapping;
	map<int, ll> rmapping;
	int ct = N + 1; 
    forn(i,1,N) {
        cin>>a[i].st>>a[i].nd;
		int sum = a[i].st + a[i].nd;
		int diff = a[i].st - a[i].nd;
		ll mul = a[i].st * a[i].nd;

		int sumidx, diffidx, mulidx;
		if (!mapping.count(sum)) {
			mapping[sum] = ct;
			rmapping[ct]=  sum;
			sumidx = ct++;
		} else sumidx = mapping[sum];

		if (!mapping.count(diff)) {
			mapping[diff] = ct;
			rmapping[ct] = diff;
			diffidx = ct++;
		} else diffidx = mapping[diff];

		if (!mapping.count(mul)) {
			mapping[mul] = ct;
			rmapping[ct] = mul;
			mulidx = ct++;
		} else mulidx = mapping[mul];

		G[i].pb(sumidx);
		G[i].pb(diffidx);
		G[i].pb(mulidx);

		G[sumidx].pb(i);
		G[diffidx].pb(i);
		G[mulidx].pb(i);
    }
	n = N;
	m = 3 * N;
    match.assign(4  * N + 1, 0); dist.assign(4  * N + 1, 0);
    int ans = hopcroft_karp();
	if (ans != N) {
		cout << "impossible\n";
		return 0;
	}

    vi allright(4 * N + 1, 0);
    while(true) {
        bool can = false;
        forn(i, 1, 4 * N) {
            for (auto &v : G[i]) {
                if (match[i] == NIL && match[v] != NIL && allright[v] == 0) {
                    allright[v]=1;
                    match[match[v]] = NIL;
                    can = true;
                }
            }
        }
        if (!can) break;
    }
    forn(i,1,4 * N)
        if (match[i] != NIL && !allright[i] && !allright[match[i]]) 
            allright[i] = 1;
    forn(i,1, N) 
		if (allright[i]) {
			ll res = rmapping[match[i]];
			if (a[i].st + a[i].nd == res) {
				cout << a[i].st << " + " << a[i].nd << " = " << res <<'\n';
			} else if (a[i].st * a[i].nd == res) {
				cout << a[i].st << " * " << a[i].nd << " = " << res <<'\n';
			} else if (a[i].st - a[i].nd == res) {
				cout << a[i].st << " - " << a[i].nd << " = " << res <<'\n';
			}
		}
	return 0;
}
