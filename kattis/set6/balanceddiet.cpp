/** 
The truth. It is a beautiful and terrible thing, and should therefore be treated with caution.        
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
const int maxn = 25;
const int maxp = 1050000;
int f,s, best,sum,nf, ns,n;
int a[maxn], b[maxn];
vi an;
int tc=0;

int getS(int mask, int* a) {
	int id = 0, res = 0;
	while(mask > 0) {
		if(mask & 1) res+=a[id];
		mask>>=1;id++;
	}
	return res;
}
void solve1() {
	an.clear();
	forn(i,0,(1 << nf) - 1) {
		an.pb(getS(i, a));
	}
	sort(all(an));
}

void solve2() {
	forn(i,0,(1 << ns) - 1) {
		int ss = getS(i, b);
		int idx = lower_bound(all(an), sum/2 - ss) - an.begin();
		forn(i,0,3) {
			if (idx+i < sz(an) && abs(sum - ss - an[idx+i] -  ss - an[idx+i]) < best) {
				best = abs(sum - ss - an[idx+i] -  ss - an[idx+i]);
				f = max(sum - ss - an[idx+i], ss + an[idx+i]);
				s = min(sum - ss - an[idx+i], ss + an[idx+i]);
			}
		}
		
		
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	while(cin>>n && n) {
		nf = n/2;
		ns = n-nf;
		sum=0;
		forn(i,0,nf-1){
			cin>>a[i];
			sum+=a[i];
		}
		forn(i,0,ns-1){
			cin>>b[i];
			sum+=b[i];
		}
		best=INF;f=0;s=0;
		solve1();
		solve2();
		cout << f<< ' ' << s << '\n';
		tc++;
	}
	return 0;
}
