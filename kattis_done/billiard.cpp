/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?        
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
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double RAD_to_DEG(double r) { return r*180.0 / PI; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b, s, m, n;
	while(true) {
		cin >> a >> b >> s >> m >> n;
		if (a == 0 && b == 0 && s == 0
			&& m == 0 && n == 0) break;
		cout << fixed << setprecision(2);
		cout << RAD_to_DEG(atan2(n * b, m * a)) << ' ';
		cout << hypot(m * a, n * b)/s << '\n';
	}
	return 0;
}
