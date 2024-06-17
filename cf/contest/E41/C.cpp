/** 
Those who do not understand true pain can never understand true peace.        
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

struct Piece {
	vector<string> b;
};

int diff(string &s, string &t) {
	int ret = 0;
	forn(i,0,sz(s)-1) {
		if(s[i]!=t[i]) ret++;
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<Piece> a(4);
	forn(i,0,3) {
		a[i].b.resize(n);
		forn(j,0,n-1) cin>>a[i].b[j];
	}
	vi t;
	forn(i,0,3) t.pb(i);
	vector<string> st(2);
	int cur = 0;
	forn(i,0,n-1) {
		char next = '0' + cur;
		st[0]+=next;
		cur = 1 - cur;
	}
	forn(i,0,n-1) st[1]+=(st[0][i] == '0' ? '1' : '0');
	// forn(i,0,1) debug(st[i]);
	int ans = INF;
	do {
		// vector<string> board;
		// forn(i,0,n-1) board.pb(a[t[0]].b[i] + a[t[1]].b[i]);
		// forn(i,0,n-1) board.pb(a[t[2]].b[i] + a[t[3]].b[i]);
		// forn(i,0,1) {
		// 	int stidx=i;
		// 	string nxt;
		// 	int curscore=0;
		// 	forn(i,0,2*n-1) {
		// 		nxt=st[stidx];
		// 		stidx^=0;
		// 		curscore+=diff(nxt, board[i]);
		// 	}
		// 	forn(i,0,2*n-1) cout << board[i] <<'\n';
		// 	debug(curscore);
		// 	ans=min(ans, curscore);

		// }
		int curscore = 0;
		int stidx=0;
		forn(i,0,n-1) {
			curscore+=diff(a[t[0]].b[i], st[stidx]);
			curscore+=diff(a[t[1]].b[i], st[stidx]);
			stidx=1-stidx;
		}
		stidx=1;
		forn(i,0,n-1) {
			curscore+=diff(a[t[2]].b[i], st[stidx]);
			curscore+=diff(a[t[3]].b[i], st[stidx]);
			stidx=1-stidx;
		}
		ans=min(curscore, ans);
	} while(next_permutation(all(t)));
	cout<< ans<<'\n';
	return 0;
}
