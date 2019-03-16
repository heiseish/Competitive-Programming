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
vi intToVec(int N) {
    vi ans;
    while(N > 0) {
        int b = N%10;
        ans.pb(b);
        N/=10;
    }
    reverse(all(ans));
    return ans;
}

void compareAndTrim(vi& lhs, vi& rhs) {
    int minSize = min(lhs.size(), rhs.size());
    forn(i, 0, minSize - 1) {
        if (lhs[lhs.size() - 1 - i] > rhs[rhs.size() - 1 - i])
            rhs[rhs.size() - 1 - i] = -1;
        else if (lhs[lhs.size() - 1 - i] < rhs[rhs.size() - 1 - i])
            lhs[lhs.size() - 1 - i] = -1;
    }
}

int toInt(vi a) {
    vi temp;
    while(!a.empty()) {
        int cur = a.back();a.pop_back();
        if (cur != -1) temp.pb(cur);
    }
    if (temp.empty()) return -1;
    int ans = 0;
    while(!temp.empty()) {
        ans+=temp.back();
        ans*=10;
        temp.pop_back();
    }
    return ans/10;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        
    }
}