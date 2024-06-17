/** 
Every human being relies on and is bounded by his knowledge and experience to live. This is what we call “reality”. However, knowledge and experience are ambiguous, thus reality can become illusion. Is it not possible to think that, all human beings are living in their assumptions?        
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
vi getd(int k) {
	vi ans;
	forn(i,1,sqrt(k)) {
		if (k%i==0) {
			ans.pb(i);
			ans.pb(k/i);
		}
	}
	sort(all(ans));
	UNIQUE(ans);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	string s;
	cin>>n>>s;
	vi d=getd(n);
	for(auto &i : d) {
		int cur=i-1;
		forn(j, 0, cur/2) 
			swap(s[j], s[cur-j]);
	}
	cout<<s<<'\n';
	return 0;
}
