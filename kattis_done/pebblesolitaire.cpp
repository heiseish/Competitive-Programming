/** 
Justice isn’t something that you can just proclaim. It’s a feeling you should keep near your heart.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
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
int ans;
int dp[1 << 12];
void play(int state) {
	if (dp[state] != -1) return;
	dp[state] = 1;
	bool can = false;
	forn(i,0,11) {
		if (state & (1 << i)) {
			if (i <= 9 && (state & (1 << (i + 1)) && !(state & (1 << (i + 2))))) {
				int pos = state;
				pos &= ~(1 << i);
				pos &= ~(1 << (i + 1));
				pos |= (1 << (i + 2));
				play(pos);
				can = true;
			}
			if (i >= 2 && (state & (1 << (i - 1)) && !(state & (1 << (i - 2))))) {
				int pos = state;
				pos &= ~(1 << i);
				pos &= ~(1 << (i - 1));
				pos |= (1 << (i - 2));
				play(pos);
				can = true;
			}
		}
	}
	if (!can) ans = min(ans, __builtin_popcount(state));
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		string s;
		cin>>s;
		int state = 0;
		for (auto &ch : s) {
			if (ch == 'o') state+=1;
			state <<=1;
		}
		state >>=1;
		ans = INF;
		memset(dp, -1, sizeof dp);
		play(state);
		cout << ans << '\n';
	}
	return 0;
}
