/** 
Is a reason necessary? I don't know why you would kill someone but as for saving someone…a logical mind isn\'t needed, right?        
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
const int maxn = 1e5 + 1;
int d[2 * maxn + 3];
int num[2 * maxn + 3];
ll sum[2 * maxn + 3];

inline int find(int index) {
	if (d[index] == -1) return index;
	return d[index] = find(d[index]);
}

inline bool isSameSet(int a, int b) {
	return find(a) == find(b);
}

inline void join(int a, int b) {
	if (isSameSet(a, b)) return;
	a = find(a);
	b = find(b);
	if (a == b) return;
	d[a] = b;
	sum[b]+=sum[a];
	num[b]+=num[a];
	sum[a]=0LL;
	num[a]=0;
}

inline void move(int a, int b) {
	if (isSameSet(a, b)) return;
	b = find(b);
	int group = find(a);
	sum[group]-=a;
	num[group]--;
	d[a] = b;
	sum[b]+=a;
	num[b]++;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n,m;
	while(cin>>n>>m) {
		memset(d, -1, sizeof d);
		forn(i, 1, n) {
			d[i] = maxn + i;
			num[maxn + i] = 1;
			sum[maxn + i] = i;
		}
		forn(i, 1, m) {
			int s;
			cin>>s;
			if (s == 1) {
				int a, b;
				cin>>a>>b;
				join(a, b);
			} else if (s == 2) {
				int a, b;
				cin>>a>>b;
				move(a, b);
			} else {
				int a;
				cin>>a;
				int group = find(a);
				cout << num[group] << ' ' << sum[group] <<'\n';
			}
		}
		// cout<<"======\n";
		// forn(i, 1, n) {
		// 	cout << i << ' ' << num[maxn + i] << ' ' << sum[maxn + i] <<'\n';
		// }

	}
	return 0;
}
