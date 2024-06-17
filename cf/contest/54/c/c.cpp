/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ld = long double;

const int N = 1e3 + 5;
ll l[N], r[N], ten[20];
ld f[N], dp[N][N];

auto solve() -> void
{
    int n;
    cin >> n;
    ten[0] = 1;
    for (int i = 1; i <= 18; ++i)
    {
        ten[i] = ten[i - 1] * 10;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
        ll num = 0;
        for (int j = 0; j <= 18; ++j)
        {
            ll low = ten[j];
            ll high = ten[j] * 2 - 1;

            if (l[i] > high)
                continue;
            if (r[i] < low)
                break;

            low = max(low, l[i]);
            high = min(high, r[i]);

            num += high - low + 1;
        }
        f[i] = (ld)1.0 * num / (r[i] - l[i] + 1);
    }

    ld k;
    cin >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[i][j] = (1.0 - f[i]) * dp[i - 1][j];
            if (j > 0)
                dp[i][j] += f[i] * dp[i - 1][j - 1];
        }
    }

    ld ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        if ((ld)100.0 * i / n >= k)
        {
            ans += dp[n][i];
        }
    }
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
