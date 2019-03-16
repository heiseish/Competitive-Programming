/** 
Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, k;
	string s;
	cin>>n>>k>>s;
	map<char, deque<int> > mti;
	forn(i,0,n-1) mti[s[i]].pb(i);
	vector<char> ans(n, ' ');
	for (auto &l : mti) {
		if (k == 0) break;
		if (sz(l.nd) <= k) {
			k-=sz(l.nd);
			l.nd.clear();
		} else {
			while(k-->0) l.nd.pop_front();
		}
	}
	for (auto &l : mti) {
		for (auto &ch : l.nd) {
			ans[ch] = l.st;
		}
	}
	for (auto & ch : ans) {
		if (ch==' ') continue;
		else cout<<ch;
	}
	cout<<'\n';

	return 0;
}
