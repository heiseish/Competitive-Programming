/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int MOD = 998244353;
int a[N], b[N], f[N];

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

int mod_inverse(int b, int m = MOD)
{
    return bin_pow(b, m - 2);
}
auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int num_miss = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0 && b[i] == 1)
        {
            num_miss++;
        }
    }
    f[0] = 0;
    for (int i = 1; i <= num_miss; ++i)
    {
        auto num = mul(2 * i, i);
        auto denom = mul(n, n - 1);
        auto xx = mul(num, mod_inverse(denom));
        f[i] = add(f[i - 1], mod_inverse(xx));
    }
    cout << f[num_miss] << endl;
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
