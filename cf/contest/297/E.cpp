/** 
Three times now… We’ve fought world wars for our own nations, our own villages. We’ve hurt one another. We’ve hated one another. That hatred bred a lust for power, and that lust for power created ME. I was a Jinchuuriki, the embodiment of hatred and power. And I hated this world, and all the people in it… I wanted to destroy it with my own hands. The exact same thing Akatsuki is trying to do today. But one man, one ninja from Konoha stopped me. I was his enemy, yet he wept for me! I hurt him, yet he called me his friend! He saved me! My enemy, my fellow Jinchuuriki… He suffered the same pain as me, yet bore no ill will! There are no enemies here because we’ve all suffered at Akatsuki’s hand! SO THERE IS NO SAND, NO STONE, NO LEAF, NO MIST, NO CLOUD! THERE ARE ONLY SHINOBI! And if you still hold a grudge against the Sand, then when this war is over, come and take my head instead! Our enemies are after the friend who saved my life! If they take him, if we hand him over, our world is finished! I want to protect him, and I want to protect our world! But I’m too young to protect it all on my own! All of you lend me your aid!        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
const int maxn = 27;
int n, k;
ll s;
int a[maxn];
unordered_map<ll, int> dp[30];
ll f[20];
ll ans = 0LL;
void solve1(int idx, int fact, ll curSum) {
	if (curSum > s) return;
	if (idx == n/2) {
		dp[fact][curSum]++;
		return;
	}
	solve1(idx+1, fact, curSum + a[idx]);
	solve1(idx+1, fact, curSum);
	if (a[idx] <= 19 && fact < k) solve1(idx+1, fact+1, curSum + f[a[idx]]);
}

void solve2(int idx, int fact, ll curSum) {
	if (curSum > s) return;
	if (idx == n) {
		forn(i,0,k-fact) {
			if (dp[i].count(s-curSum))
				ans += dp[i][s-curSum];
		}
		return;
	}
	
	solve2(idx+1, fact, curSum);
	solve2(idx+1, fact, curSum+a[idx]);
	if (a[idx]<=19 && fact < k) solve2(idx+1, fact+1, curSum + f[a[idx]]);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	f[1]=1;
	forn(i, 2, 19) f[i]=i*f[i-1];
	cin>>n>>k>>s;
	forn(i,0,n-1) cin>>a[i];
	solve1(0, 0, 0);
	solve2(n/2, 0, 0);
	cout<<ans<<'\n';
	return 0;
}
