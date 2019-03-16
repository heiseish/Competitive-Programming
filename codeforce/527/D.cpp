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
int N;
vector<bool> pos;

int getNext(int i) {
    while(i < N && pos[i]) i++;
    return i;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vi h(N);
    int hi = -1;
    forn(i, 0, N - 1) {
        cin >> h[i];
        hi = max(hi, h[i]);
    }
        
    pos.assign(N, false);
    vi cant;
    forn(i, 0, N - 2) {
        if (pos[i]) continue;
        int p = 1 + i;
        if (!pos[p] && h[i]==h[p]) {
            pos[i] = true;
            pos[p] = true;
            if (cant.empty()) continue;
            int cur = h[i];
            int a = cant.back(), b = p + 1;
            
            while(b <= N - 1 && !pos[a] && !pos[b] && h[a]==h[b] && h[a] >= cur) {
                cant.pop_back();
                pos[a] = true;
                pos[b] = true;
                cur = h[a];
                if (cant.empty()) break;
                a = cant.back(); 
                b++;
            }
            i = b - 1;
        } 
        if (!pos[i]) {
            cant.pb(i);
        }
    }
    int ct = 0, idx =-1;
    forn(i, 0, N - 1) {
        if (!pos[i]) {
            ct++;
            idx = i;
        }
    }
    if (ct == 0 || (ct ==1 && h[idx] == hi)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}