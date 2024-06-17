/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
double dp[N][N];

auto recurse(int w, int b) -> double
{
    if (w < 0 || b < 0)
        return 0.;

    if (dp[w][b] != -1.0)
        return dp[w][b];

    // drawing white mice directly
    auto ans = (1.0 * w) / (w + b);

    // win after next turn
    if (b == 1)
    {
        return dp[w][b] = ans;
    }
    auto nxt_b = b - 1;

    auto other = (1.0 * b) / (w + b) * (1.0 * nxt_b) / (w + nxt_b);

    // black mice jumps out
    auto chance = 1.0 * w / (w + nxt_b - 1) * recurse(w - 1, nxt_b - 1);
    if (nxt_b > 0)
    {
        chance += 1.0 * (nxt_b - 1) / (w + nxt_b - 1) * recurse(w, nxt_b - 2);
    }
    other *= chance;
    return dp[w][b] = ans + other;
}

auto solve() -> void
{
    int w, b;
    cin >> w >> b;
    for (int i = 0; i <= w; ++i)
        for (int j = 0; j <= b; ++j)
            dp[i][j] = -1.0;

    for (int i = 0; i <= b; ++i)
        dp[0][i] = 0.0;
    for (int i = 1; i <= w; ++i)
        dp[i][0] = 1.0;

    cout << fixed << setprecision(9) << recurse(w, b) << endl;

    // for (int i = 0; i <= w; ++i)
    // {
    //     for (int j = 0; j <= b; ++j)
    //     {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
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
