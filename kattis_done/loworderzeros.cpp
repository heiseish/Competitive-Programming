/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
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
ll mem[maxn];

int trim(ll a) {
	while(a%10==0) a/=10;
	return a%10000;
}
void preprocess() {
	mem[0] = 1;
	forn(i, 1, maxn - 3) {
		mem[i] = trim(1L *  mem[i - 1] * i);
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	preprocess();
	while(scanf("%d", &n) && n) {
		printf("%d\n", mem[n]%10);
	}
	return 0;
}
