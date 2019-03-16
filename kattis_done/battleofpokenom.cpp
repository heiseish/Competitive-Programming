/** 
Courage is a word of justice. It means the quality of mind that enables one to face apprehension with confidence and resolution. It is not right to use it as an excuse to kill someone        
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
		int k;
		cin>>k;
		vector<char> ash(k), brock(k);
		int s1=0,s2=0;
		int s=2*k;
		int t1=k, t2=k;
		int sc1=0, sc2=0;
		forn(i,0,2*k-1){
			if (s1 > s2 + t2 || s2 > s1 + t1) {
					if (s > i) {
						s=i;
						sc1=s1;
						sc2=s2;
					}
				}
			int turn=i/2;
			if (i%2==0) {
				cin>>ash[turn];
				t1--;
				if (ash[turn]=='E') s1++;
			} else {
				cin>>brock[turn];
				t2--;
				if (brock[turn]=='E') s2++;
			}
		}
		if (s==2*k) {
			sc1=s1;
			sc2=s2;
		}
		t1=s%2==0?s/2 : s/2 + 1;
		t2 = s - t1;
		s1=0; s2=0;
		int c = s;
		// debug(sc1);
		// debug(sc2);
		forn(i, 0, s-1) {
			int turn=i/2;
			// debug(s1);
			// debug(t1);
			// debug(s2);
			// debug(t2);
			if ((s1==sc1 || s1 + t1 == sc1) && (s2==sc2 || s2 + t2 == sc2)) 
				c=min(c, i);
			if ((s1==sc1 || s1 + t1 == sc1) && (s2+1==sc2))
				c=min(c, i);
			if ((s2==sc2 || s2 + t2 == sc2) && (s1 + 1 == sc1))
				c=min(c, i);
			if (s1 >= s2 + t2 || s2 >= s1 + t1)
				c=min(c, i);
			if (i%2==0) {
				if (ash[turn] =='E') s1++;
				t1--;
			} else {
				if (brock[turn] =='E') s2++;
				t2--;
			}
		}
		cout << s<<' ' << c <<'\n';
	}
	return 0;
}
