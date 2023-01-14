/** 
it is foolish to fear what we have to see and know”        
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
	int n;
	int cur = 1;
	while(true) {
		cin >> n;
		if (n == 0) break;
		cin.ignore();
		map<string, int> g;
		forn(i, 1, n) {
			string animal;
			getline(cin, animal);
			stringstream ss(animal);
			string last;
			while(ss >> last);
			for (auto &ch : last) ch = tolower(ch);
			g[last]++;
		}
		cout << "List " << cur++ << ":\n";
		for (auto &v : g) cout << v.st << " | " << v.nd << '\n';
	}
	return 0;
}
