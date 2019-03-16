/** 
...people live their lives bound by what they accept as correct and true... that is how they define reality. But what does it mean to be correct or true? Merely vague concepts... their reality may all be an illusion        
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
//need to sort first b4 using unique

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
struct State {
	vpi a;

	State() { a.assign(4, {0, 0})};
	bool operator==(const State& other) {
		forn(i, 0, 3) {
			if (a[i] != other.a[i])
				return false;
		}
		return true;
	}
	bool operator<(const State& other) {
		forn(i, 0, 3) {
			if (a[i] < other.a[i])
				return true;
		}
		return false;
	}
	void organize() { sort(all(a)); }
};

void explore(State st) {
	queue<pair<int, State> > q;
	q.push({0, st});
	while(!q.empty()) {
		pair<int, State> cur = q.front();q.pop();
		
	}
}
vector<State> fromSt, fromEn;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	State st, en;
	forn(i,0,3) cin >> st.a[i].st >> st.a[i].nd;
	st.organize();
	forn(i,0,3) cin >> en.a[i].st >> en.a[i].nd;
	en.organize();
	explore(st);
	solve(en);
	return 0;
}
