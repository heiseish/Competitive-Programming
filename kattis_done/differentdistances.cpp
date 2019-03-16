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
    double x1, y1, x2, y2, p;
    string inp;
    while(1) {
        getline(cin, inp);
        if (inp == "0") break;
        stringstream ss(inp);
        ss >> x1 >> y1 >> x2 >> y2 >> p;
        double f = pow(abs(x1 - x2), p);
        double s = pow(abs(y1 - y2), p);
        cout << setprecision(10) << pow(f + s, 1/p) << '\n';
    }
    return 0;
}