/** 
How often have I said to you that when you have eliminated the impossible, whatever remains, however improbable, must be the truth?        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
//need to sort first b4 using unique

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
const int MAX_L = 20+3;
char trash[MAX_L];

inline ll getSec(int y, int m, int d, int h, int mi) {
    tm t = {};
    t.tm_hour = h;
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_min = mi;
    time_t tt = mktime(&t);
    return tt;
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    #ifdef LOCAL_PROJECT
        freopen("input.txt","r",stdin);
    #endif
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int b, c;
        scanf("%d %d", &b, &c);
        c*=60;
        priority_queue <ll, vector<ll>, greater<ll> > q;
        vector<pair<ll, ll> > inp(b);
        forn(i, 0, b-1) {
            scanf("%s", trash);
            int y, m, d, h, mi;
            scanf("%d-%d-%d %d:%d", &y, &m, &d, &h, &mi);
            ll arrival = getSec(y, m, d, h, mi);
            scanf("%d-%d-%d %d:%d", &y, &m, &d, &h, &mi);
            ll departure = getSec(y, m, d, h, mi);
            inp[i] = { arrival, departure };
        }
        sort(all(inp));
        for (auto &p : inp) {
            if (q.empty()) q.push(p.nd);
            else {
                ll f = q.top();
                if (f + c <= p.st) {
                    q.pop();
                    q.push(p.nd);
                } else q.push(p.nd);
            }
        }
        printf("%d\n", sz(q));

    }
    return 0;
}