/** 
A detective who uses his deductive powers to corner a suspect, and then does nothing to stop them from committing suicide, is no better than the murderer himself.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 1 << 30;
/**
Start coding from here
*/
const int maxn = 53;
const int maxr = 53;
ll C[maxn][maxr];
void precomputeNChooseR(int n) {
    for (int i = 0; i <= n; ++i) { 
        for (int j = 0; j <= min(i, n); ++j) { 
            if (j == 0 || j == i)  C[i][j] = 1; 
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
}


template <class T>
T fastpow(T a, int b) {
	T ret = 1;
	while (b) {
		if (b & 1) {
			ret = ret * a;
		}
		a = a * a;
		b >>= 1;
	}
	return ret;
}

double probOfWinningExactK(int k, int n, double chance) {
	return C[n][k] * fastpow<double>(chance, k) * fastpow<double>(1 - chance, n-k);
}
double probOfWinningMoreThanK(int k, int n, double chance) {
	double prob = 0.0;
	for(int i = k; i<= n;++i) 
		prob += probOfWinningExactK(i, n, chance);
	return prob;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	precomputeNChooseR(50);
	const double WINNING_CHANCE = 0.5;
	while(tc--) {
		int n, v1, v2, w;
		cin>>n>>v1>>v2>>w;
		int m = v1 + v2;
		int vl = n - m;
		if (v1 + vl <= v2) {
			cout << "RECOUNT!\n";
			continue;
		}

		int need = n/2+1;
		int l = need - v1;
		if (l <= 0) {
			cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
			continue;
		} 
		double prob = probOfWinningMoreThanK(l, vl, WINNING_CHANCE);
		double thres = 1.0 * w / 100;
		if (abs(prob - thres) <= 1e-9 || prob < thres) {
			cout << "PATIENCE, EVERYONE!\n";
			continue;
		} else  {
			cout  << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
			continue;
		}
	}
	return 0;
}
