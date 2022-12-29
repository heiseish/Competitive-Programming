/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	vi r(N);
	forn(i, 0, N - 1) cin >> r[i];
	forn(i, 1, N - 1) {
		int g = gcd(r[0], r[i]);
		cout << r[0]/g << "/" << r[i]/g << '\n';
	}
	return 0;
}
