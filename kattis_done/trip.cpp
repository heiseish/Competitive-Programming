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
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int N;
    while(scanf("%d", &N) && N) {
        vi c(N);
        ll sum = 0L;
        forn(i, 0, N - 1) {
            int d, ce;
            scanf("%d.%d", &d, &ce);
            c[i] = d * 100 + ce;
            sum+=c[i];
        }
        ll avg = sum/N;
        ll residue = sum%N;
        vll toPay(N);
        forn(i, 0, N - 1) {
            toPay[i] = avg;
            if (i < residue) toPay[i]++;
        }
        sort(all(c));
        sort(all(toPay));
        ll change = 0;
        forn(i, 0, N - 1) {
            change+=abs(c[i] - toPay[i]);
        }
        change/=2;
        printf("$%d.%02d\n", change/100, change%100);
    }
}