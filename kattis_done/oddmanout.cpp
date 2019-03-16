/** 
Legends from the distant past are always exaggerated. But eventually, someone outdoes them. That's when new legends are born.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x
#define sz(x) (int)x.size()

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc;
	cin>>tc;
	int c=1;
	while(tc--){
		int n;
		cin >>n;
		unordered_map<int, int> g;
		while(n--) {
			int t;
			cin>>t;
			g[t]++;
		}
		for(auto&v:g) 
			if(v.nd==1) cout<<"Case #"<<c++<< ": "<<v.st <<'\n';
	}
	return 0;
}
