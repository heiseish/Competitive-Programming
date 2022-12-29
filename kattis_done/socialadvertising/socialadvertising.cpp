/** 
Regardless of our limitations, we can always be of some use. Our power may seem insignificant… but it may just prove to be useful in the grand scheme of things. Stay focused. Never avert your eyes, because if an opening arises, even our insignificant power may be enough to determine the fate of the world.        
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
const int maxn = (1 << 20) + 1;
int g[maxn];
int n;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    cin>>tc;
    while(tc--) {
        cin >> n;
		int DONE = (1 << n) - 1;
        forn(i,0,n-1) {
            int k;
            cin>>k;
            int a;
            g[1 << i] = (1 << i);
            forn(j,1,k) {
                cin>>a;
                g[1 << i] |= (1 << (a - 1));
            }
        }
		int fin = INF;
        forn(i,1,(1 << n) - 1) {
			int pos = i;
			int can = 0;
			while(pos) {
				int p = pos & -pos;
				can |= g[p];
				pos-=p;
			}
			if (can == DONE) fin=min(fin, __builtin_popcount(i));
		}
		cout << fin << '\n';
    }
    return 0;
}