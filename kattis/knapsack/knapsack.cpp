/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first

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

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 2e3 + 7;
int wt[maxn], v[maxn];
int dp[maxn][maxn];
int n, c;

void solve() { 
    forn(i, 0, n) { 
        forn(w, 0, c) { 
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (wt[i] <= w) 
                dp[i][w] = max(v[i] + dp[i - 1][w - wt[i]], 
							   dp[i - 1][w]); 
            else
                dp[i][w] = dp[i - 1][w]; 
        } 
    } 

    int res = dp[n][c];     
    int w = c; 
	vi resA;
    for (int i = n; i > 0 && res > 0; i--) { 
        if (res == dp[i - 1][w]) continue;         
        else { 
			resA.pb(i - 1);
            res -= v[i]; 
            w -= wt[i]; 
        } 
    } 
	printf("%ld\n", resA.size());
	for (auto i : resA) printf("%d ", i);
	printf("\n");
} 

int main() { 
    double dc;
	while(scanf("%lf %d", &dc, &n) != EOF) {
		c = floor(dc);
		forn(i, 1, n) scanf("%d %d", &v[i], &wt[i]);
		solve(); 
	}
    return 0; 
} 