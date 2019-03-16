/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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
const int N = 2e5 + 3;
int n;
int contains[N];
vi g[N];
int roots[N];
int pre[N], post[N];
int dfs(int index) {
    int ans = 1;
    for (auto &v : g[index]) {
        ans += dfs(v);
    }
    return contains[index] = ans;
}

void preorder(int index) {
	static int t= 1;
	pre[index] = t++;
	for (auto &v : g[index]) preorder(v);
}

void postorder(int index) {
	static int t = 1;
	for (auto &v : g[index]) postorder(v);
	post[index] = t++;
}

const int maxk = 20;
int l[maxk], nu[maxk];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    cin>>n;
	int m;
    forn(i,1,n) {
        cin>>m;
        if (m==0) roots[i]++;
        else g[m].pb(i);
    }
    forn(i,1,n) if (roots[i]) {
		dfs(i);
		preorder(i);
		postorder(i);
	}
    int q;
    cin>>q;
    int k;
    while(q--) {
        cin>>k;
        int ans = 0;
        forn(i,0,k-1) {
            cin>>l[i];
            ans += contains[l[i]];
        }
        memset(nu, false, sizeof nu);
        forn(i,0,k-1) {
            forn(j,i+1,k-1) {
                if (nu[i] || nu[j]) continue;
                if (pre[l[i]] < pre[l[j]] && post[l[i]] > post[l[j]]) {
					nu[j] = true;
                    continue;
				}
                if (pre[l[i]] > pre[l[j]] && post[l[i]] < post[l[j]]) {
                    nu[i] = true;
                    break;
                }
            }
        }
        forn(i,0,k-1) if(nu[i]) ans-=contains[l[i]];
        
        cout << ans <<'\n';
    }
    
    return 0;
}
