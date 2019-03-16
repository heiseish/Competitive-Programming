/** 
Those who do not understand true pain can never understand true peace.        
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
	int h1,w1,h2,w2,h3,w3;
	cin>>h1>>w1>>h2>>w2>>h3>>w3;
	int area = h1 * w1 + h2 * w2 + h3 * w3;
	int k = sqrt(area);
	if (k * k != area || k != h1) {
		cout << "NO\n";
	} else {
		if (w2 + w3 == k && h2 == h3 && h2 + w1 == k) {
			cout << "Yes\n";
		} else if (w2 == h3 && h2 + w3 == k && w2 + w1 == k) {
			cout << "Yes\n";
		} else if (h1 == h2 && h2 == h3 && w1 + w2 + w3 == k) {
			cout << "Yes\n";
		} else cout << "No\n";
	}

	return 0;
}
