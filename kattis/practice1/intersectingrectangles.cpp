/** 
People become stronger because they have things they cannot forget. That’s what you call growth.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;++i)
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
struct r{
	int x1, y1, x2, y2;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<r> a(n);
	forn(i,0,n-1)cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
	sort(all(a), [](const r& lhs, const r& rhs) {
		return lhs.x1 < rhs.x1;
	});
	int rightmost = -1e9 - 1;
	for (auto &v : a) {
		if (a.x1 <= )
	}
	return 0;
}
