/** 
Those who cannot acknowledge themselves will eventually fail.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
	int k;
	const string e = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	while(true) {
		cin >> k;
		if (k == 0) break;
		string in, out = "";
		cin >> in;
		for (auto &ch : in) out += e[(e.find(ch) + k)%e.length()];
		for(int i = out.length() - 1; i >= 0; i--) cout << out[i];
		cout << '\n';
	}
	return 0;
}
