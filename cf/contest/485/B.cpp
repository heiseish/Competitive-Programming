/** 
It takes a great deal of bravery to stand up to our enemies, but just as much to stand up to our friends.        
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
const double EPS = 1e-7;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int x, y;
	cin>>x>>y;
	if (x==y) {
		cout << "=\n";
		return 0;
	}
	double x1 = 1.0 * log(1.0 * x) * y;
	double x2 = 1.0 * log(1.0 * y) * x;
	if (abs(x1 - x2) < EPS) cout << "=\n";
	else if (x1 > x2) cout << ">\n";
	else if (x1 < x2) cout << "<\n";
	return 0;
}
