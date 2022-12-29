/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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
const int MAX_N = 200 + 2;
string s;
int dp[MAX_N][MAX_N];
int solve(int i, int j) {
	if (dp[i][j]) return dp[i][j];
	if (i == j) return dp[i][j] = 1;
	int &ans = dp[i][j];
	ans = INF;
	int l = j - i + 1;
	forn(k, 0, l - 2) {
		ans = min(ans, solve(i, i + k) + solve(i + k + 1, j));
	}
	//scan for repeating sequences
	forn(k, 1, l - 1) {
		if (l%k!=0) continue;
		bool can = true;
		string ini = s.substr(i, k);
		int start = i + k;
		while(start + k <= j + 1) {
			if (s.substr(start, k) != ini) {
				can = false;
				break;
			}
			start+=k;
		}
		if (can) ans = min(ans, solve(i, i + k - 1));
	}
	return ans;

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp, 0, sizeof dp);
	cin >> s;
	int l = s.length();
	kakimasu(solve(0, l-1));
	return 0;
}
