/** 
if you don’t like your destiny, don’t accept it .instead ,have the courage to change it.        
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
struct Claus {
	int st, nd, rd;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, m;
	cin>>m>>n;
	if (m < 8) cout << "unsatisfactory\n";
	else cout << "satisfactory\n";
	// vector<Claus> a(m);
	// forn(i,0,m-1) {
	// 	cin>>a[i].st>>a[i].nd>>a[i].rd;
	// 	if (a[i].st < 0) a[i].st = abs(a[i].st) + n;
	// 	if (a[i].nd < 0) a[i].nd = abs(a[i].nd) + n;
	// 	if (a[i].rd < 0)  a[i].rd = abs(a[i].rd) + n;
	// 	a[i].st--; a[i].nd--; a[i].rd--;
	// }
	// forn(i,0,(1 << n) - 1) {
	// 	bool can = true;
	// 	for (auto &c : a) {
	// 		int f = c.st > n - 1 ? !(i & (1 << (c.st - n))) : (i & (1 << c.st));
	// 		int s = c.nd > n - 1 ? !(i & (1 << (c.nd - n))) : (i & (1 << c.nd));
	// 		int t = c.rd > n - 1 ? !(i & (1 << (c.rd - n))) : (i & (1 << c.rd));
	// 		if (f || s || t) continue;
	// 		can = false;
	// 		break;
	// 	}
	// 	if (can) {
	// 		cout << "satisfactory\n";
	// 		return 0;
	// 	}
	// }
	// cout << "unsatisfactory\n";
	return 0;
}
