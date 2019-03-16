/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?        
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
const int maxn = 65;
int a[maxn];
vi g[maxn];

int toInt(char ch) {
	return (int) (ch - '0');
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	cin>>n>>m;
	string s, t;
	forn(i,1,m) {
		cin>>s>>t;
		int f = s[1] == 'w' ? 2 * toInt(s[0]) : toInt(s[1]);
		int se = t[1] == 'w' ? 2 * toInt(t[0]) : toInt(t[1]);
		g[f].pb(se);
		g[se].pb(f);
	}
	return 0;
}
