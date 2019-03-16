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
bool valid(char ch) {
    return isdigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string inp;
    vector<string> res;
    while(getline(cin, inp) && !cin.eof()) {
        forn(i, 0, inp.length() - 2) {
            if (inp[i] == '0' && (inp[i + 1] == 'X' || inp[i + 1] == 'x')) {
                string ans = "0x";
                int cur = i + 2;
                while(cur < inp.length() && valid(inp[cur])) {
                    ans+=inp[cur++];
                }
                if (ans.length() > 2)
                    res.pb(ans);
            }
        }
    }
    
    for (auto &s : res) {
        stringstream ss(s);
        ll a;
        ss >> hex >> a;
        cout << s << ' ' << a << '\n';
    }
    return 0;
}