/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
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
	string s;
	cin>>s;
	int l=sz(s);
	int openbrack = -1, closebrack = -1;
	int stcolon = -1, clcolon = -1;
	forn(i, 0, l-1) {
		if(s[i]=='[' && openbrack==-1)openbrack=i;
		if(s[i]==':'&& stcolon==-1 && openbrack !=-1) stcolon=i;
	}
	for(int i =l-1;i>=0;i--) {
		if(s[i]==']' && closebrack==-1)closebrack=i;
		if(s[i]==':'&& clcolon==-1&& closebrack !=-1) clcolon=i;
	}
	if (openbrack==-1 || closebrack==-1 || stcolon==-1 ||
		clcolon==-1 ||  stcolon >= clcolon) puts("-1");
	else {
		int ct=0;
		forn(i,stcolon,clcolon) {
			if(s[i]=='|') ct++;
		}
		cout << 4 + ct <<'\n';
	}
	return 0;
}
