/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int MOD = 998244353;
const int N = 1e5 + 7;
vector<pair<int, int>> g[N];
int c[2][N], d[2][N], dp[N];
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

auto dfs(int idx) -> void
{
    int cur = 0;
    c[0][idx] = 0;
    c[1][idx] = 0;
    for (const auto &[nxt, w] : g[idx])
    {
        c[w][idx] = add(c[w][idx], 1);
        if (w == 0)
        {
            cur = add(cur, c[1][idx]);
        }
        if (dp[nxt] == -1)
        {
            dfs(nxt);
        }
        cur = add(cur, dp[nxt]);
        cur = add(cur, mul(c[1][idx], c[0][nxt]));

        c[0][idx] = add(c[0][idx], c[0][nxt]);
        c[1][idx] = add(c[1][idx], c[1][nxt]);
    }
    dp[idx] = cur;
}

auto solve() -> void
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; ++j)
        {
            int l, w;
            cin >> l >> w;
            g[i].emplace_back(l, w);
        }
    }
    dfs(1);
    cout << dp[1] << '\n';
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
