/** 
Those who do not understand true pain can never understand true peace.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sseuda(x) cout << x
#define sz(x) (int)x.size()

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
const int MOD=1e9+7;
const double EPS = 1e-9;

int determinant(vector<vector<double> >& a, int n)  {  
    ld det = 1.0;
	for (int i=0; i<n; ++i) {
		int k = i;
		for (int j=i+1; j<n; ++j)
			if (abs (a[j][i]) > abs (a[k][i]))
				k = j;
		if (abs (a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap (a[i], a[k]);
		if (i != k)
			det = -det;
		det*=a[i][i];
		for (int j=i+1; j<n; ++j)
			a[i][j] /= a[i][i];
		for (int j=0; j<n; ++j)
			if (j != i && abs (a[j][i]) > EPS)
				for (int k=i+1; k<n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}
	det=fmod(det, MOD);
	return det;

} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	while(tc--) {
		int n, m;
		cin>>n>>m;
		vector<vector<double> > degree(n, vector<double>(n, 0.0));
		vector<vector<double> > adjmat(n, vector<double>(n, 0.0));
		forn(i, 0, m-1) {
			int a, b;
			cin>>a>>b;
			degree[a-1][a-1]+=1;
			degree[b-1][b-1]+=1;
			adjmat[a-1][b-1]=1.0;
			adjmat[b-1][a-1]=1.0;
		}
		forn(i, 0, n-1) forn(j,0,n-1)
			degree[i][j]-=adjmat[i][j];
		cout << determinant(degree, n - 1) <<'\n';
	}
	return 0;
}
