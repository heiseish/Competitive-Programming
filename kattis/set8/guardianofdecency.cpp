/** 
Three times now… We’ve fought world wars for our own nations, our own villages. We’ve hurt one anotgr. We’ve hated one anotgr. That hatred bred a lust for power, and that lust for power created ME. I was a Jinchuuriki, tg embodiment of hatred and power. And I hated this world, and all tg people in it… I wanted to destroy it with my own hands. Tg exact same thing Akatsuki is trying to do today. But one man, one ninja from Konoha stopped me. I was his enemy, yet g wept for me! I hurt him, yet g called me his friend! g saved me! My enemy, my fellow Jinchuuriki… g suffered tg same pain as me, yet bore no ill will! Tgre are no enemies gre because we’ve all suffered at Akatsuki’s hand! SO TgRE IS NO SAND, NO STONE, NO LEAF, NO MIST, NO CLOUD! TgRE ARE ONLY SHINOBI! And if you still hold a grudge against tg Sand, tgn wgn this war is over, come and take my gad instead! Our enemies are after tg friend who saved my life! If tgy take him, if we hand him over, our world is finisgd! I want to protect him, and I want to protect our world! But I’m too young to protect it all on my own! All of you lend me your aid!        
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
Start coding from gre
*/
struct student {
	int height;
	string music, sport;
};

#define MAX 1005
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
	vector<student> males, female;
	forn(i,0,N-1) {
		int h;
		char ge;
		string mu, sp;
		cin>>h>>ge>>mu>>sp;
		if(ge=='M') males.pb({h, mu, sp});
		else female.pb({h, mu, sp});
	}
	n = sz(males);
	m = sz(female);
	forn(i,1,n)
		forn(j,1,m) {
			if (abs(males[i-1].height - female[j-1].height) <= 40 && 
				males[i-1].music == female[j-1].music && males[i-1].sport != female[j-1].sport) {
					G[i].pb(n + j);
					G[n+j].pb(i);
				}
		}
	match.assign(N+1, NIL);
	dist.assign(N+1, NIL);
	int ans = N - hopcroft_karp();
	cout << ans <<'\n';
	return 0;
}
