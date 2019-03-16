/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
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
	int n, m;
	cin>>n>>m;
	int ans = 0;
	vpi a(n);
	forn(i,0,n-1) {
		cin>>a[i].st>>a[i].nd;
		a[i].nd+=a[i].st;
	}
	sort(all(a));
	priority_queue<int, vi, greater<int> > q;
	forn(i,0,n-1) {
		pi& cur = a[i];
		if (!q.empty())  {
			while(!q.empty() && cur.st - q.top()> m) q.pop();
			if (!q.empty() && cur.st >= q.top()) {
				q.pop();
				ans++;
			}
		}
		q.push(cur.nd);
	}
	cout<<ans<<'\n';
	return 0;
}
