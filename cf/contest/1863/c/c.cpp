/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
using ll = long long;
ll a[N];
auto solve() -> void
{
    ll n, k;
    cin >> n >> k;
    ll s = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    a[n] = n * (n + 1) / 2 - s;

    // for (int i = 0; i <= n; ++i)
    //     cerr << a[i] << ' ';
    // cerr << '\n';
    for (ll i = 0; i < n; ++i)
    {
        ll idx = (i + k * n) % (n + 1);
        // cerr << i << ' ' << idx << '\n';
        cout << a[idx] << ' ';
    }
    cout << '\n';
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
