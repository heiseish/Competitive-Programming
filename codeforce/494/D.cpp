/** 
Justice isn’t something that you can just proclaim. It’s a feeling you should keep near your heart.        
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
const int maxn = 33;
int a[maxn];
int solve(int x) {
	vi bits;
	while(x>0) {
		bits.pb((int)(x&1));
		x>>=1;
	}
	reverse(all(bits));
	int l=sz(bits)-1;
	int ans =0;
	forn(i,0,l) {
		if(bits[i] <= a[l-i]) ans+=bits[i];
		else {
			if(i==l) return -1;
			else {
				ans+=a[l-i];
				bits[i+1]+=(bits[i]-a[l-i])*2;
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, q;
	cin>>n>>q;
	ll t;
	forn(i,0,n-1){
		cin>>t;
		a[(int)log2(t)]++;
	}
	while(q--) {
		int x;
		cin>>x;
		cout<<solve(x)<<'\n';
	}
	return 0;
}
