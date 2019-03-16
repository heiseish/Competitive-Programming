/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
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
int n;
void print(deque<int> &a) {
	for (auto &v : a) cout << v <<' ';
	cout <<'\n';
}
vector<vector<deque<int> > > g(9);
void get(int l) {
	if (!g[l].empty()) return;
	if (n == l + 1) {
		g[l] =  {{l, n}, {n, l}};
		return;
	}
	int f = l;
	get(l+1);
	bool front = true;
	for (auto &v : g[l+1]) {
		if (front) {
			v.push_front(f);
			forn(i,0,sz(v)-1) {
				g[l].pb(v);
				if (i < sz(v)-1) swap(v[i], v[i+1]);
			}
			front = false;
		} else {
			v.push_back(f);
			for(int i = sz(v)-1; i >= 0; i--) {
				g[l].pb(v);
				if (i > 0) swap(v[i-1], v[i]);
			}
			front = true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	cin>>n;
	if (n==1) {
		puts("1");
		return 0;
	}
	get(1);
	for (auto &v : g[1]) print(v);
}
