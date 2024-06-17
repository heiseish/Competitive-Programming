/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
int a[N], b[N];
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
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    int num = 1;
    int denom = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != 0 && b[i] != 0)
        {
            if (a[i] < b[i])
            {
                break;
            }
            else if (a[i] > b[i])
            {
                ans = add(ans, mul(num, mod_inverse(denom)));
                break;
            }
        }
        else if (a[i] == 0 && b[i] == 0)
        {
            auto nn = mul(num, m - 1);
            auto mm = mul(denom, 2 * m);
            ans = add(ans, mul(nn, mod_inverse(mm)));

            denom = mul(denom, m);
        }
        else if (a[i] == 0)
        {
            if (b[i] == m)
            {
                denom = mul(denom, m);
                continue;
            }
            auto nn = mul(num, m - b[i]);
            denom = mul(denom, m);
            ans = add(ans, mul(nn, mod_inverse(denom)));
        }
        else
        {
            if (a[i] == 1)
            {
                denom = mul(denom, m);
                continue;
            }
            auto nn = mul(num, a[i] - 1);
            denom = mul(denom, m);
            ans = add(ans, mul(nn, mod_inverse(denom)));
        }
    }
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
