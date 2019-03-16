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
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())

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
struct Road {
	int o,k,s;
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int l, w;
	cin>>l>>w;
	vector<Road> r(l);
	forn(i,0,l-1) cin>>r[l-1-i].o>>r[l-1-i].k>>r[l-1-i].s;
	int x;
	string seq;
	cin>>x>>seq;
	int times=0;
	int y=-1;
	for(auto &ch:seq) {
		if (ch=='U') {
			y++;
		} else if (ch=='D') {
			if (y>=1) y--;
		} else if (ch=='L') {
			x--;
			x=max(x,0);
			
		} else  {
			x++;
			x=min(x, w-1);
		}
		if (y==l) {
			cout<<"safe\n";
			exit(0);
		}
		if (y==-1) {
			times++;
			continue;
		}
		int fcs=r[y].o+r[y].s*times;
		while(fcs>=0) fcs-=r[y].k;
		int X = (y%2==(l-1)%2? x: w-1-x);
		for(int z=fcs; z<=w-1;z+=r[y].k) {
			if ((r[y].s==0 && X==z) || (r[y].s > 0 && X>=z+1 && X<=z+r[y].s)) {
				cout<<"squish\n";
				exit(0);
			}
		}
		times++;
	}
	cout<<"squish\n";
	return 0;
}
