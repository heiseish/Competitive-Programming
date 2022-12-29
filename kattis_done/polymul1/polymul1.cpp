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
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a;
        vi f(a + 1);
        forn(i, 0, a) cin >> f[i];
        cin >> b;
        vi s(b + 1);
        forn(i, 0, b) cin >> s[i];
        vi r(a + b + 1, 0);
        forn(j, 0, b)
            forn(i, 0, a) {
                r[i + j]+=f[i]*s[j];
            }
        cout << a + b << '\n';
        forn(i, 0, a + b) cout << r[i] << ' ';
        cout << '\n';
    }
    return 0;
}