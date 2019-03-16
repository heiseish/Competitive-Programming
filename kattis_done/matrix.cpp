#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define rsa(x, y) memset(x, y, sizeof x);

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
const int EPS = 1e-9;
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c, d;
    int cur = 1;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
        double det = 1.0 / (a * d - b * c + EPS);
        printf("Case %d:\n", cur++);
        printf("%d %d\n", (int) det * d, (int) det * -1 * b);
        printf("%d %d\n",  (int) det * -1 * c, (int) det * a);
    }
    return 0;
}