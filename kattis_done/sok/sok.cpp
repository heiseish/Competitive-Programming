/** 
A trick is nothing but a puzzle mankind came up with. If you use your head, you can uncover the logical answer.        
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
	vi f(3),s(3);
	forn(i,0,2)cin>>f[i];
	forn(i,0,2)cin>>s[i];
	double next=INF;
	int idx=-1;
	forn(i,0,2) {
		if(1.0*f[i]/s[i]<next){
			next=1.0*f[i]/s[i];
			idx=i;
					}
	}
	vector<double> ans(3);
	ans[idx]=0.0;
	double prop=1.0*f[idx]/s[idx];
	forn(i,0,2){
		if(i==idx) continue;
		ans[i]=1.0*f[i]-prop*s[i];
	}
	cout<<setprecision(15);
	for(auto&v:ans) cout << v << ' ';
	cout <<'\n';
	return 0;
}
