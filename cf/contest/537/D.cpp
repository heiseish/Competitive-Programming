/** 
If it’s an important memory, then you shouldn't forget it. Since those who aren't with us only live on in our memories.        
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
const int MOD = 1e9 + 7;
const int N = 100010;
void add(int& a, int b) {
	a+=b;
	if (a >= MOD) a -= MOD;
}

int sum (int a, int b) {
	add(a, b);
	return a;
}

int sub(int& a, int b) {
	a-=b;
	if (a<0) a+=MOD;
}

int multiply(int a, int b) {
	return (long long) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = multiply(ret, a);
		}
		a = multiply(a, a);
		b >>= 1;
	}
	return ret;
}

ll buc[101];
ll fac[N],inv[N];
int dp[N],temp_dp[N];
ll ans[55][55];
string s,s1,s2;

/**
Convert char to int
*/
int find(char c) {
    if(c>='A' && c<='Z')
		return (int)(c-'A'+26);
    else return (c-'a');
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1,n,i,j,m,q;
    cin>>s;
    n = s.length();
    //Store the frequencies in buc
    for(int i=0;i<n;i++)
		buc[find(s[i])]++;
    
    //Compte factorial and inverse factorials modulo mod
    fac[0]=1;
    forn(i,1,n)
		fac[i]=multiply(fac[i-1],i);;
    inv[n] = mpow(fac[n], MOD-2);
    for(int i=n-1;i>=0;i--)
		inv[i]=mpow(inv[i+1], i+1);


    //Compute n/2! * n/2! divided by factorials of frequencies of all
    ll num = multiply(fac[n/2], fac[n/2]);
    for(int i=0;i<52;i++)
		num = multiply(num, inv[buc[i]]);

    //DP for subset sum
    dp[0]=1;
    forn(i,0,51) {
        if(!buc[i]) continue;
        for(int j=n;j>=buc[i];j--)
            add(dp[j], dp[j-buc[i]]);
    }
    forn(i,0,51)
		ans[i][i]=dp[n/2];

    forn(i,0,51) {
        if(!buc[i])continue;
        //Temporrily store dp using all characters in an array
        for(int k=0;k<=n;k++)
            temp_dp[k]= dp[k];

        //Remove all ways consisting of the ith character from temp array
        for(int k=buc[i];k<=n;k++)
            sub(temp_dp[k], temp_dp[k-buc[i]]);
        

        for(int j=i+1;j<52;j++) {
            if(!buc[j])continue;
            //Now remove the jth character from the temp
            for(int k=buc[j];k<=n;k++)
                sub(temp_dp[k],temp_dp[k-buc[j]]);

            // Answer will be twice since ith and jth can be in 1st or 2nd half
            ans[i][j]= multiply(2ll, temp_dp[n/2]);
            ans[j][i]= ans[i][j]; //Symmetric
                
            //Restore condition by adding ways using jth to reset temp to without i
            for(int k=n;k>=buc[j];k--)
                add(temp_dp[k],temp_dp[k-buc[j]]);
        }
    }
    cin>>q;
    int x,y;
    while(q--) {
        cin>>x>>y;
        int l = find(s[x-1]);
        int r = find(s[y-1]);
        //Use precomputed num and ans, for all queries
        cout<< multiply(num, ans[l][r]) <<"\n";
    }
    
    return 0;
}