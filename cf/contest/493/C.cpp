/** 
Wherever someone is still thinking of you, that place is your home.        
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
	ll n, x, y;
	cin>>n>>x>>y;
	string s;
	cin>>s;
	bool isZ = false;
	int no = 0;
	for (auto &ch : s) {
		if (ch == '0') isZ = true;
		else {
			if (isZ) no++;
			isZ = false;
		}
	}
	if (isZ) no++;
	if (no == 0) {
		puts("0");
		return 0;
	}
	ll ans=1LL << 60;
	forn(i,0,no-1) ans=min(ans, x * i +  y * (no - i));
	cout << ans<<'\n';
	return 0;
}
