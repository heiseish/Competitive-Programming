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
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		vector<string> b(3);
		forn(i,0,2)cin>>b[i];
		int ctx=0, cto=0;
		int xwin=0, owin=0;
		forn(i,0,2) forn(j,0,2) 
			if (b[i][j]=='X') {
				ctx++;
				if (i==0 && b[i+1][j] == 'X' && b[i+2][j]  == 'X') xwin++;
				if (j==0 && b[i][j+1] =='X' && b[i][j+2] =='X') xwin++;
				if (i==0&&j==0&&b[i+1][j+1]=='X'&&b[i+2][j+2]=='X') xwin++;
			} else if (b[i][j]=='O') {
				if (i==0 && b[i+1][j] == 'O' && b[i+2][j]  == 'O') owin++;
				if (j==0 && b[i][j+1] =='O' && b[i][j+2] =='O') owin++;
				if (i==0&&j==0&&b[i+1][j+1]=='O'&&b[i+2][j+2]=='O') owin++;
				cto++;
			}
		if (xwin > 0 && owin > 0) cout << "no\n";
		else if (xwin==1 && ctx==cto) cout << "no\n";
		else if (owin==1 && ctx==cto+1) cout <<"no\n";
		else if (ctx>=cto && abs(ctx-cto)<=1) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
