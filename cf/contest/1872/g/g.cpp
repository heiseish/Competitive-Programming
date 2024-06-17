/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 2e5 + 7;
using ll = long long;
ll a[N];
bool w[N];
auto solve() -> void
{
    int n;
    cin >> n;
    int k = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        w[i] = false;
        if (a[i] == 1)
            k = i;
    }

    int l = 1, r = n;
    while (a[l] == 1 && l < n)
    {
        l++;
    }

    while (r > l && a[r] == 1)
    {
        r--;
    }
    ll cost = 0;
    
    for (int i = l; i <= r; ++i) {

    }
    cout << l << ' ' << r << '\n';
}
auto main() -> int
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
