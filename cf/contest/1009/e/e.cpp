/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], g[N], f[N];
const int MOD = 998244353;

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    g[n] = 1;
    for (int i = n - 1; i >= 1; --i)
    {
        g[i] = mul(g[i + 1], 2);
    }

    f[1] = mul(g[1], a[1]);
    for (int i = 2; i <= n; ++i)
    {
        auto temp = f[i - 1];
        temp = add(temp, -mul(g[i - 1], a[i - 1]));
        temp = add(temp, mul(g[i], a[i - 1]));
        temp = add(temp, mul(g[i], a[i]));
        f[i] = temp;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = add(ans, f[i]);

    cout << ans << endl;
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
