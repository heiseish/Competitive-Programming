/** 
People become stronger because they have things they cannot forget. That’s what you call growth.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi diff(n-1), f(n-1);
	int mincur = 0;
	forn(i,0,n-2) {
		cin>>diff[i];
		if (i > 0) f[i] = f[i-1] + diff[i];
		else f[i] = diff[i];
		if (f[i] < mincur) mincur = f[i];
	}
	int st = 1-mincur;
	if (st < 1 || st > n) {
		puts("-1");
		return 0;
	}
	vi ans;
	ans.pb(st);
	vi check(n+1, 0);
	check[st]++;
	bool can = true;
	forn(i,0,n-2) {
		int nxt = st + diff[i];
		if (nxt < 1 || nxt > n || check[nxt]++) can = false;
		ans.pb(nxt);
		st = nxt;
	}
	if (can) {
		for (auto &v : ans)
			cout << v <<" ";
		cout <<"\n";
	} else {
		puts("-1");
	}
	return 0;
}
