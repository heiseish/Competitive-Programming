#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())

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

const int maxn = 20 + 7;
int main() {
	int t;
	while(scanf("%d", &t) && t != -1) {
		int adjm[maxn][maxn];
		unordered_map<int, vi> adjl;
		forn(i, 0, t-1) {
			forn(j,0,t-1) {
				scanf("%d", &adjm[i][j]);
				if (adjm[i][j]) {
					adjl[i].push_back(j);
					adjl[j].push_back(i);
				}
			}
		}
		forn(i, 0, t-1) {
			bool can = false;
			if (adjl.find(i) == adjl.end()) {
				printf("%d ", i);
				continue;
			}
			forn(j, 0, adjl[i].size() - 1) {
				forn(k, j + 1, adjl[i].size()-1) {
					if (adjm[adjl[i][j]][adjl[i][k]]) {
						can = true;
						break;
					}
				}
				if (can) break;
			}
			if (!can) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
