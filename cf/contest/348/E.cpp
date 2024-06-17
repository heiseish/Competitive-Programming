/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
struct query {
	int t,m,val,idx;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<query> q(n);
	forn(i,0,n-1) {
		cin>>q[i].t>>q[i].m>>q[i].val;
		q[i].idx=i;
	}
	vi ans(n,-1);
	sort(all(q), [](const query& lhs, const query& rhs) {
		return lhs.m<rhs.m;
	});
	unordered_map<int, int> z;
	for(auto &v : q) {
		if (v.t==1) {
			z[v.val]++;
		} else if(v.t==2) {
			z[v.val]--;
		} else {
			ans[v.idx]=z[v.val];
		}
	}
	for(auto &v : ans) 
		if(v!=-1)cout<<v<<'\n';
	return 0;
}
