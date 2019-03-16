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
int toDec(string orig, string base) {
    int b = base.length();
    int ans = 0;
    forn(i, 0, orig.length() - 1) 
        ans+= base.find(orig[orig.length() - 1 - i]) * pow(b, i);
    return ans;
}

string toBase(int val, string base) {
    int b = base.length();
    string res = "";
    while(val >= b) {
        int re = val%b;
        res = base[re] + res;
        val/=b;
    }
    res = base[val] + res;
    return res;
}
int main() {
    int tc;
    cin >> tc;
    forn(i, 1, tc) {
        string an,sl,tl;
        cin >> an >> sl >> tl;
        int dec = toDec(an, sl);
        cout << "Case #" << i << ": " << toBase(dec, tl) << '\n';
    }
    return 0;
}