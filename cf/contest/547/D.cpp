/** 
Life is short so it will be appreciated. We live to our fullest due to that.        
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
	cin >>n;
	string l, r;
	cin>>l>>r;
	vector<pair<char, int> > ll(n), rr(n);
	forn(i,0,n-1) {
		ll[i] = {l[i], i+1};
		rr[i] = {r[i], i+1};
	}
	sort(all(ll), greater<pair<char, int> > ());
	sort(all(rr), greater<pair<char, int> > ());
	int lidx = 0, ridx = 0;
	vpi ans;
	vector<int> checkl(n+1, 0), checkr(n+1, 0);
	int posleft = n, posright = n;
	forn(i,0,n-1) {
		if (ll[i].st == '?') posleft = min(posleft, i);
		if (rr[i].st == '?') posright = min(posright, i);
	}
	while(lidx < n && ridx < n) {
		if (ll[lidx].st == rr[ridx].st && ll[lidx].st != '?') {
			ans.pb({ll[lidx].nd, rr[ridx].nd});
			checkl[lidx]++;
			checkr[ridx]++;
			lidx++;
			ridx++;
		} else {
			if (ll[lidx].st > rr[ridx].st) {
				lidx++;
			} else {
				ridx++;
			}
		}
	}
	int cr = 0;
	while(posleft != n && cr < n) {
		while(posleft < n && checkl[posleft]) posleft++;
		if (posleft == n) break;
		while(cr < n && checkr[cr]) cr++;
		if (cr == n) break;
		ans.pb({ll[posleft].nd, rr[cr].nd});
		checkr[cr]++;
		checkl[posleft]++;
		posleft++;
		cr++;
	}

	
	int cl = 0;
	while(posright < n && cl < n) {
		while(posright < n && checkr[posright]) posright++;
		if (posright == n) break;
		while(cl < n && checkl[cl]) cl++;
		if (cl == n) break;
		ans.pb({ll[cl].nd, rr[posright].nd});
		checkl[cl]++;
		checkr[posright]++;
		cl++;
		posright++;
	}

	cout << sz(ans) <<'\n';
	for (auto &v : ans) cout << v.st << ' ' << v.nd <<'\n';
	return 0;
}
