/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
using ld = long double;
ld a[N], p[N], dp[N], f[N];
auto prob(int i, int j) -> ld
{
    return p[j] / p[i - 1];
}
auto solve() -> void
{
    int n;
    cin >> n;
    ld ans = 0.0;
    p[0] = 1.0;
    f[0] = 0.0;
    a[0] = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ans += a[i];
        p[i] = a[i] * p[i - 1];
        f[i] = f[i - 1] + a[i - 1];
        f[i] *= a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + f[i];
    }
    ans += 2 * dp[n];
    cout << fixed << setprecision(15) << ans << endl;
}
auto main() -> int
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}
