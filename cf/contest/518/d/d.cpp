/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
double f[N][N];
auto solve() -> void
{
    int n, t;
    double p;
    cin >> n >> p >> t;

    for (int i = 0; i <= n; ++i)
    {
        f[i][0] = 0.0;
    }
    f[0][0] = 1.0;
    for (int j = 1; j <= t; ++j)
    {
        for (int i = 0; i <= n; ++i)
        {
            if (i == n)
            {
                f[i][j] = f[i][j - 1] + p * f[i - 1][j - 1];
            }
            else if (i == 0)
            {
                f[i][j] = (1.0 - p) * f[i][j - 1];
            }
            else
            {
                f[i][j] = p * f[i - 1][j - 1] + (1.0 - p) * f[i][j - 1];
            }
        }
    }
    double ans = 0.0;

    // for (auto i = 0; i <= n; ++i)
    // {
    //     for (auto j = 0; j <= t; ++j)
    //     {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; ++i)
    {
        ans += f[i][t] * i;
    }
    cout << fixed << setprecision(6) << ans << endl;
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
