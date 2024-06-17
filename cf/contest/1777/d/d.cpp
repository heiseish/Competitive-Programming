/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
const int MOD = 1e9 + 7;

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

using Depth = int;

auto solve() -> void
{
    int n;
    cin >> n;
    vvi g(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int fc = bin_pow(2, n);
    int fc_1 = bin_pow(2, n - 1);
    int ans = 0;

    function<int(int, int)> dfs = [&](int idx, int p) -> Depth
    {
        auto maxd = 0;
        for (const auto &v : g[idx])
        {
            if (v == p)
                continue;
            maxd = max(maxd, dfs(v, idx));
        }
        ans = add(ans, mul(maxd + 1, fc_1));
        return maxd + 1;
    };

    dfs(1, -1);
    cout << ans << endl;
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
