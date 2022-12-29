/** 
it is foolish to fear what we have to see and know”        
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

void convert(string& s) {
	int shift = 0;
	for (auto &ch : s) shift+=(ch-'A');
	shift%=26;
	for (auto &ch:s) {
		int next = (ch - 'A') + shift;
		next%=26;
		ch=('A' + next);
	}
}
string merge(string&f, string&n) {
	int l=sz(f);
	string ans;
	forn(i, 0, l - 1) {
		int next = (f[i] - 'A') + (n[i]-'A');
		next%=26;
		ans+=('A' + next);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin>>s;
	int l=sz(s);
	string f=s.substr(0, l/2);
	string n=s.substr(l/2);
	convert(f);
	convert(n);
	string ans = merge(f, n);
	cout << ans<<'\n';
	return 0;
}
