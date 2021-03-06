/** 
Three times now… We’ve fought world wars for our own nations, our own villages. We’ve hurt one another. We’ve hated one another. That hatred bred a lust for power, and that lust for power created ME. I was a Jinchuuriki, the embodiment of hatred and power. And I hated this world, and all the people in it… I wanted to destroy it with my own hands. The exact same thing Akatsuki is trying to do today. But one man, one ninja from Konoha stopped me. I was his enemy, yet he wept for me! I hurt him, yet he called me his friend! He saved me! My enemy, my fellow Jinchuuriki… He suffered the same pain as me, yet bore no ill will! There are no enemies here because we’ve all suffered at Akatsuki’s hand! SO THERE IS NO SAND, NO STONE, NO LEAF, NO MIST, NO CLOUD! THERE ARE ONLY SHINOBI! And if you still hold a grudge against the Sand, then when this war is over, come and take my head instead! Our enemies are after the friend who saved my life! If they take him, if we hand him over, our world is finished! I want to protect him, and I want to protect our world! But I’m too young to protect it all on my own! All of you lend me your aid!        
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
int ans = 0, OK;
const int maxn = 13;
int board[1 << 12][maxn];
int n, m;
void backtrack(int rw, int ld, int rd) {
	if (rw == OK) { ans++; return; }
	int pos = OK & (~(rw | ld | rd));
	while(pos) {
		int p = pos & -pos;
		pos -=p;
		if (!board[p][__builtin_popcount(rw)]) 
			backtrack(rw | p, (ld | p) << 1, (rd | p) >> 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	while(cin>>n>>m) {
		if (m == 0 && n == 0) break;
		OK = (1 << n) - 1;
		ans = 0;
		vpi k(m);
		forn(i,0,m-1) {
			cin>>k[i].st>>k[i].nd;
			board[1 << k[i].st][k[i].nd]++;
		}
		backtrack(0, 0 , 0);
		forn(i,0,m-1) {
			board[1 << k[i].st][k[i].nd] = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}
