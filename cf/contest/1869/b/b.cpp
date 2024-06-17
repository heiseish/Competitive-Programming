/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 6;
ll x[N], y[N];
auto solve() -> void
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    ll ans = abs(x[a] - x[b]) + abs(y[a] - y[b]);
    ll maxa = ans, maxb = ans;
    for (int i = 1; i <= k; ++i)
    {
        maxa = min(maxa, abs(x[i] - x[a]) + abs(y[i] - y[a]));
        maxb = min(maxb, abs(x[i] - x[b]) + abs(y[i] - y[b]));
    }
    ans = min(ans, maxa + maxb);
    cout << ans << '\n';
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
