/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 4e3 + 5;
int dp[N][N];
int add(int a, int b)
{
    a += b;
    a %= MOD;
    if (a < MOD)
        a += MOD;
    return a % MOD;
}
int mul(int a, int b)
{
    return (long long)a * b % MOD;
}

int bin_pow(int a, int b)
{
    a %= MOD;
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int mod_inverse(int b, int m)
{
    return bin_pow(b, m - 2);
}
auto solve() -> void
{
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = k - 1; j >= 1; --j)
        {
            cur = add(cur, dp[i][j]); // partial sum
            dp[i + 1][j] = cur;
        }

        for (int j = k - 1; j >= 0; --j)
        {
            // choose the next element to add to 2nd state
            auto nxt = (j + 1) % k;
            dp[i + 1][nxt] = add(dp[i + 1][nxt], mul(dp[i][j], k - j));
        }
        ans = add(ans, mul(dp[i + 1][0], bin_pow(k, n - (i + 1))));
    }
    cout << ans << '\n';
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
