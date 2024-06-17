/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int a[N];
int n, p;
double dp[N][N][N];

auto solve() -> void
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cin >> p;
    dp[0][0][0] = 1.0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            auto temp = 1.0 * j / i;
            for (int k = 0; k <= p; ++k)
            {
                dp[i][j][k] += dp[i - 1][j][k] * (1 - temp);
                if (a[i] <= k)
                {
                    dp[i][j][k] += dp[i - 1][j - 1][k - a[i]] * temp;
                }
            }
        }
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= p; ++j)
        {

            ans += dp[n][i][j];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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
