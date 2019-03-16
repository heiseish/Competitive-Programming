/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.        
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
#define sz(x) (int)x.size()

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
	// freopen("input.txt", "r", stdin);
	string s;
	cin>>s;
	int n=sz(s);
	int curlen=n;
	ll ct=0L;
	for(int i = n-1;i>=0;i--) {
		if (s[i]=='2') {
			ct+=curlen-i-1;
			curlen--;
		}
	}
	int idx=curlen-1;
	for(int i=n-1;i>=0;i--) {
		if (s[i]=='1') {
			ct+=curlen-idx-1;
			curlen--;
		}
		if (s[i]=='1' || s[i]=='0') idx--;
	}
	cout<<ct<<'\n';
	return 0;
}
