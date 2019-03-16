/** 
Hard work is worthless for those that don’t believe in themselves.        
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
bool can = false;
bool isPal(string& t) {
	int l = sz(t);
	forn(i,0,sz(t)/2) {
		if (t[i] != t[l-1-i]) return false;
	}
	return true;
}
int cut(string &s) {
	if(sz(s)%2==1) {
		s = s.substr(0, sz(s)/2);
		return 2;
	} else {
		s = s.substr(0, sz(s)/2);
		return 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	string s;
	cin>>s;
	int ct = 0;
	while(sz(s) > 3 && !can) {
		if (ct == 0) ct+=cut(s);
		else ct += 2*cut(s);
		can |= !isPal(s);
	}
	if(can) cout << ct <<'\n';
	else cout << "Impossible\n";
	return 0;
}
