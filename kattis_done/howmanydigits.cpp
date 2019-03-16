/** 
Wherever someone is still thinking of you, that place is your home.        
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
const int maxn = 1e6 + 3;
int n;
double dp[maxn] = { 0.0 };
void preprocess() {
	dp[0] = 0.0;
	int e = 1e6;
	forn(i, 1, e) {
		dp[i] = dp[i - 1] + log10(i);
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	preprocess();
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", (int) floor(dp[n]) + 1);
	}
	return 0;
}
