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
bool toNum(string orig, int base, int& result) {
    result = 0;
    if (base == 1) {
        for (auto &ch : orig)
            if (ch != '1')
                return false;
        result = orig.length();
        return true;
    }
    for (int i = 0; i < orig.length(); i++) {
        char n = orig[orig.length() - 1 - i];
        int equi;
        if (isdigit(n)) equi = n - '0';
        else equi = n - 'a' + 10;
        if (equi >= base) return false;
        result+= equi * pow(base, i);
    }
    return true;
}
int main() {
    int N;
    cin >> N;
    cin.ignore();
    while(N--) {
        string temp;
        getline(cin, temp);
        stringstream ss(temp);
        vi ans;
        string f, s, r;
        char op, _;
        ss >> f >> op >> s >> _ >> r;
        int fn, sn, rn;
        forn(i, 1, 36) {
            if (!toNum(f, i, fn) || !toNum(s, i, sn) || !toNum(r, i, rn)) 
                continue;
            if (op == '+' && fn + sn == rn) ans.pb(i);
            if (op == '-' && fn - sn == rn) ans.pb(i);
            if (op == '*' && fn * sn == rn) ans.pb(i);
            if (op == '/' && fn%sn == 0 && fn/sn == rn) ans.pb(i);
        }
        if (ans.size() == 0)
            cout << "invalid\n";
        else {
            for (auto &v : ans) {
                char tp = '0' + v;
                if (v >= 10 && v < 36) {
                    tp = 'a' + (v - 10);
                }
                if (v == 36) tp = '0';
                cout << tp;
            }
            cout << '\n';
        }
        
    }
}