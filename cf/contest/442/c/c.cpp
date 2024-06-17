/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> g[N];
int inv[N], ss[N], choosekd2[N];

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
    return a * b % MOD;
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

int extended_euclid(int a, int b, int &x, int &y)
{
    int xx = y = 0;
    int yy = x = 1;
    while (b)
    {
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

int mod_inverse(int b, int m)
{
    int x, y;
    int d = extended_euclid(b, m, x, y);
    if (d != 1)
        return -1;
    return add(x, 0);
}
int choose(int n, int k)
{
    if (k == 0)
        return 1;
    return mul(mul(n, inv[k]), choose(n - 1, k - 1));
}

auto precal_inv(int n) -> void
{
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = add(MOD, -mul((MOD / i), inv[MOD % i]));
}

auto dfs(int idx) -> int
{
    int ans = 0;
    for (const auto &v : g[idx])
    {
        ans += dfs(v);
    }
    return ss[idx] = ans;
}

auto solve() -> void
{
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    if (k % 2 == 1)
    {
        cout << 1 << endl;
        return;
    }
    precal_inv(k);
    dfs(1);

    int num = 0;
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
