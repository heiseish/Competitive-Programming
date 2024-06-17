/** 
Although this mirror can show a reflection, it cannot show you the truth.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	// if(n<10) cout << "1\n" << n<<'\n';
	// else if (n%9==0) {
	// 	cout<<n/9<<'\n';
	// 	forn(i, 1, n/9) cout << "9 ";
	// 	cout<<'\n';
	// } else {
	// 	cout<<n/9 + 1;
	// 	int ans=0;
	// 	forn(i, 1, n/9) {
	// 		cout<<"9 ";
	// 		ans+=9;
	// 	}
	// 	cout<<n-ans<<'\n';
	// }
	cout<<n<<'\n';
	forn(i, 1, n) cout << "1 ";
	cout<<'\n';
	return 0;
}
