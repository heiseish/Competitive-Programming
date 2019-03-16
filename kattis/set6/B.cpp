/** 
Hard work is worthless for those that don’t believe in themselves.        
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
#define LSOne(S) ((S) & -(S))


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
struct FenwickTreeMax {
    vector<int> bit;
    int n;

    FenwickTreeMax(int n): n(n) {
        bit.assign(n + 1, 0);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()-1) {
        for (size_t i = 1; i <= n; i++)
            update(i, a[i]);
    }

    int query(int r) {
        int ret = 0;
        for (; r; r -=LSOne(r))
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx +=LSOne(idx))
            bit[idx] = max(bit[idx], val);
    }
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n, x, y;
	while(cin>>n>>x>>y && (n||x||y)) {
		vi a(n), dp(n, 0);
		forn(i,0,n-1) {
			cin>>a[i];
			a[i]+=110;
		}
		FenwickTreeMax odd(220), even(220);
		forn(i,0,n-1) {
			if (a[i]%2==0) {
				dp[i] = 1 + odd.query(a[i]);
				even.update(a[i], dp[i]);
			} else {
				dp[i] = 1 + even.query(a[i]);
				odd.update(a[i], dp[i]);
			}
		}
		int ans = 0;
		forn(i,0,n-1) {
			int X, Y, st;
			if (a[i]%2==0) {
				if (dp[i]%2==0) {
					X = dp[i]/2; Y = X;st = 1;
				} else {
					X = dp[i]/2;Y = X + 1;st=0;
				}	
			} else {
				if (dp[i]%2==0) {
					X=dp[i]/2;Y=X;st=0;
				} else {
					Y = dp[i]/2;X = Y+1;st=1;
				}
			}
			if (X > x) {
				if (st == 1) {
					Y-= (X-x) - 1;
					X = x;
				} else {
					Y -= (X-x);
					X = x;
				}
				if ((a[i]%2==0 && X>Y) || (a[i]%2==1 && X==Y)) st = 0;
				else st=1;
			}
			if (Y > y) {
				if (st == 0) {
					X-= (Y-y) - 1;
					Y = y;
				} else {
					X -= (Y-y);
					Y = y;
				}
				if ((a[i]%2==0 && X>Y) || (a[i]%2==1 && X==Y)) st = 0;
				else st=1;
			}
			if (X < 0 || Y < 0) continue;
			ans=max(ans, X+Y);
		}
		cout << ans<<'\n';
	}
	return 0;
}
