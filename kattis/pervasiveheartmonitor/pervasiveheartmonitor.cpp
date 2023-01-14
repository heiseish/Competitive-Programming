/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
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
	// ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while(getline(cin, s) && !cin.eof()) {
		stringstream ss(s);
		string token;
		vector<string> fn;
		double hrs = 0.0;
		int ct = 0;
		while(ss >> token) {
			if (isalpha(token[0])) fn.pb(token);
			else {
				hrs += stod(token);
				ct++;
			} 
		}
		cout << fixed << setprecision(10) << hrs/ct << ' ';
		for (auto &s : fn) cout << s << ' ';
		cout << '\n';
	}
	return 0;
}
