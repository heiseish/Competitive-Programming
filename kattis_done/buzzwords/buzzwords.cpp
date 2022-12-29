/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.        
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	string s,t;
	while(getline(cin, s)) {
		stringstream ss(s);
		string r;
		while(ss >> t) r+=t;
		unordered_map<string, int> g;
		g.reserve(100000);
		int cur = 1;
		while(true) {
			int best = 0;
			forn(i,0,sz(r)-cur) {
				string k = r.substr(i, cur);
				int& a = g[k];
				a++;
				if (a > best) best = a; 
			}
			if (best <= 1) break;
			cout << best << '\n';
			cur++;
		}
		cout << '\n';
	}
	return 0;
}
