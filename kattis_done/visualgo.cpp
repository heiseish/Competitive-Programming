/* Dijkstra algorithm for Undirected Graph, time complexity : O(|E|.log|V|)  */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
int inf = 1 << 30;
vii *G;    // Graph
vi D;      // distance vector for storing min distance from the source.
vi ND;     // prev
/*=======================================*/
void dijkstra(int source,int t, int N) {
    D.assign(N,INF);
	ND.assign(N, 0);
    D[source] = 0;
	ND[source] = 1;
    set<pii> Q;
    Q.insert({0, source});
    while(!Q.empty()) {
        auto top = Q.begin();
        int u = top->second;
        Q.erase(top);
		if (u == t) break;
        for(auto next: G[u])    {
            int v = next.first, weight = next.second;
			if( D[v] == D[u] + weight) {
				ND[v] += ND[u];
			}
            if( D[v] > D[u] + weight) {
                if(Q.find( {D[v], v} ) != Q.end())
                Q.erase(Q.find( {D[v], v} ));
                D[v] = D[u] + weight;
				ND[v] = ND[u];
                Q.insert( {D[v], v} );
            }
        }
    }
}
/*==========================================*/
int main(){
    int N,M,u,v,w;
    cin >> N >> M ; 
    G = new vii[N];
    for(int i=0;i<M;i++){
        cin >> u >> v >> w; 
        G[u].push_back({v,w});
    }
	int source, t;
	cin  >> source >> t;
    dijkstra(source, t, N); 
	cout << ND[t] << endl;
}