/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " x << '\n'
using namespace std;
const int MOD = 998244353;
const int N = 2e5 + 7;
int g[N], f[N], fact[N];
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

auto solve() -> void
{
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (int i = 1; i <= n + 1; ++i)
        fact[i] = mul(fact[i - 1], i);

    int mine = max(0, n - k);
    for (int i = mine; i <= n; ++i)
        g[i] = mul(fact[n - i + 1],
                   bin_pow(n - i + 1, k - (n - i)));
    for (int i = mine; i <= n; ++i)
    {
        f[i] = add(g[i], -g[i + 1]);
    }
    int ans = 0;
    for (int i = mine; i <= n; ++i)
    {
        ans = add(ans, mul(f[i], mul(fact[n], bin_pow(fact[i], MOD - 2))));
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
