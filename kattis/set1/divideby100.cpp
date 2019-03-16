/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
	string n,m;
	cin>>n>>m;
	if(sz(m)<=sz(n)) {
		n.insert(sz(n) - sz(m) + 1,".");
	} else {
		string pad="";
		forn(i,0,sz(m) - sz(n)-2) pad+='0';
		pad="0."+pad;
		n=pad+n;
	}
	while(n.back()=='0') n.pop_back();
	if (n.back()=='.') n.pop_back();
	cout<<n<<'\n';
	return 0;
}
