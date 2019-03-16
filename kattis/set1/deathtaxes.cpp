/** 
It does not do to dwell on dreams and forget to live.        
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
	// freopen("input.txt", "r", stdin);
	double noshare =0.0, price=0.0;
	while (true) {
		string com;
		cin>>com;
		if (com=="buy") {
			int x, y;
			cin>>x>>y;
			price=(noshare*price + x*y)/(noshare+x);
			noshare+=x;
		} else if (com=="sell") {
			int x,y;
			cin>>x>>y;
			noshare-=x;
		} else if(com=="split") {
			int x;
			cin>>x;
			noshare*=x;
			price/=x;
		} else if(com=="merge") {
			int x;
			cin>>x;
			noshare = (int) floor(noshare/x);
			price*=x;
		} else {
			int x;
			cin>>x;
			double profit = 1.0*x-price;
			profit=max(profit,.0);
			double ans = noshare*(x - profit*0.3);
			cout<<setprecision(10)<<ans<<'\n';
			break;
		}
	}
	return 0;
}
