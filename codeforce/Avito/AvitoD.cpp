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
int n, m, k;
const int maxn = 1e5 + 3;
int sp[maxn], d[maxn];
bool done = false;
int find(int index) {
    if (!d[index]) return index;
    return d[index] = find(d[index]);
}
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    d[b] = a;
    sp[a] += sp[b];
    if (sp[a] == k) done = true;
}

bool isSameSet(int a, int b) {
    return find(a) == find(b);
}
int main() {
    cin >> n >> m >> k;
    forn(i, 0, k - 1) {
        int a;
        cin >> a;
        sp[a]++;
    }
    vector<pair<int, pair<int, int> > > el;
    forn(i, 0, m - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        el.pb({ w, { a, b }});
    }
    sort(el.begin(), el.end());
    int ans = -1;
    for (auto &v : el) {
        if (!isSameSet(v.nd.nd, v.nd.st))
            join(v.nd.nd, v.nd.st);
        ans = max(ans, v.st);
        if (done) break;
    
    }
    forn(i, 0, k - 1)
        cout << ans << ' ';
}