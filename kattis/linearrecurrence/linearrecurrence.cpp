/** 
Sometimes you must hurt in order to know,fall in order to grow,lose in order to gain because life’s greatest lessons are learned through pain.        
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
int MOD = 1e7 + 9;
vector<vector<long long> > matrixMulty(const vector<vector<long long> > &a, const vector<vector<long long> > &b) {
	int m=sz(a), n=sz(a[0]), p = sz(b[0]);
	vector<vector<long long> > res(m, vector<long long> (p, 0));
	for(int i=0;i<=m-1;++i) for(int j=0;j<=n-1;++j) for(int k=0;k<=p-1;++k)
		res[i][k]=(res[i][k]+1LL*a[i][j]*b[j][k])%MOD;
	return res;
}
vector<vector<long long> > matrixUnit(int n) {
	vector<vector<long long> > res(n, vector<long long> (n, 0));
	for(int i=0;i<=n-1;++i) res[i][i]=1;
	return res;
}
vector<vector<long long> > matrixPower(vector<vector<long long> > a, long long n) {
	vector<vector<long long> > res = matrixUnit(a.size());
	for(;n>0;n>>=1) {
		if (n&1) res=matrixMulty(res, a);
		a=matrixMulty(a, a);
	}
	return res;
}


void getCofactor(vector<vector<long long> > A, vector<vector<long long> >& temp, int p, int q) { 
	int n = A.size();
    int i = 0, j = 0; 
  	for (int row = 0; row < n; row++) { 
        for (int col = 0; col < n; col++) { 
            if (row != p && col != q) { 
                temp[i][j++] = A[row][col]; 
  				if (j == n - 1) { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 

long long determinant(vector<vector<long long> > A, int n)  { 
    long long D = 0;
  	if (n == 1)  return A[0][0]; 
    vector<vector<long long> > temp(n, vector<long long>(n, 0));
    int sign = 1; 
  	for (int f = 0; f < n; f++) { 
        getCofactor(A, temp, 0, f); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  		sign = -sign; 
    } 
    return D; 
} 
void adjoint(vector<vector<long long> > A,vector<vector<long long> >& adj) { 
	int n = A.size();
    if (n == 1) { 
        adj[0][0] = 1; 
        return; 
    } 
	vector<vector<long long> > temp(n, vector<long long> (n, 0));
	int sign = 1;
    for (int i=0; i<n; i++) { 
        for (int j=0; j<n; j++) { 
            getCofactor(A, temp, i, j); 
  			sign = ((i+j)%2==0)? 1: -1; 
  			adj[j][i] = (sign)*(determinant(temp, n-1)); 
        } 
    } 
} 
  
bool inverse(vector<vector<long long> > A,vector<vector<long long> >& inverse) { 
	int n = A.size();
    int det = determinant(A, n); 
    if (det == 0) { 
        cout << "Singular matrix, can't find its inverse"; 
        return false; 
    } 
	vector<vector<long long> > adj(n, vector<long long> (n, 0));
    adjoint(A, adj); 
  	for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            inverse[i][j] = adj[i][j]/float(det); 
  
    return true; 
} 

vector<vector<int> > getIdentityMatrix(int n) {
	vector<vector<int> > I(n, vector<int>(n, 0));
	forn(i,0,n-1) {
		I[i][i] = 1;
	}
	return I;
}

void substract(vector<vector<ll> >& A, vector<vector<int> > B) {
	int n = A.size();
	for(int i=0;i<n;++i) for(int j = 0;j<n;++j)
		A[i][j]-=B[i][j];
}

/**
Get n-th Fibonacci number
long long Fibonacci(int n) {
	vector<vector<long long> > base(2, vector<long long> (2, 1));
	base[0][0]=0;
	vector<vector<long long> > First(2, vector<long long> (1, 1));
	return matrixMulty(First, matrixPower(base, n+1))[1][0];
}
*/
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vector<vector<long long> > base(n, vector<long long> (n, 0));
	forn(i,1,n-1) base[i-1][i] = 1;
	vector<vector<long long> > extra(n, vector<long long> (1, 0));	
	cin >> extra[n-1][0];
	forn(i,0,n-1) cin>>base[n-1][n-1-i];

	vector<vector<long long> > First(n, vector<long long> (1, 1));
	forn(i,0,n-1) cin>>base[i][0];

	vector<vi> I  = getIdentityMatrix(n);

	int q;
	cin>>q;
	while(q--) {
		ll t;
		cin>>t>>MOD;
		if (t <= n-1) cout << base[t][0] % MOD <<'\n';
		else {
			vector<vector<long long> > res = matrixPower(base, t-n-1);
			vector<vector<long long> > c = res;
			substract(c, I);
			vector<vector<long long> > temp = base;
			substract(temp, I);
			vector<vector<long long> > inv (n, vector<long long>(n, 0));
			inverse(temp, inv);
			ll ans = (matrixMulty(First, res)[n-1][0] +  matrixMulty(extra, matrixMulty(inv, c))[n-1][0])%MOD;
			cout << ans <<'\n';
		}
	}
	return 0;
}
