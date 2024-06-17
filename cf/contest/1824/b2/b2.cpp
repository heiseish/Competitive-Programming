/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
vector<int> g[N];
int inv[N], ss[N], facts[N], ifacts[N];

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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

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
    return bin_pow(b, MOD - 2);
}
auto choose(int n, int k) -> int
{
    if (k > n)
        return 0;
    auto ret = mul(mul(facts[n], ifacts[k]), ifacts[n - k]);
    return ret;
}

auto precal_inv(int n) -> void
{
    facts[0] = 1;
    for (int i = 1; i <= n; ++i)
        facts[i] = mul(facts[i - 1], i);
    ifacts[0] = 1;
    ifacts[n] = mod_inverse(facts[n], MOD);
    for (int i = n - 1; i >= 1; i--)
        ifacts[i] = mul(i + 1, ifacts[i + 1]);
}

auto dfs(int idx, int p = -1) -> int
{
    int ans = 0;
    for (const auto &v : g[idx])
    {
        if (v == p)
            continue;
        ans += dfs(v, idx);
    }
    return ss[idx] = ans + 1;
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
    precal_inv(n);
    dfs(1);
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        num = add(num, mul(choose(ss[i], k / 2), choose(n - ss[i], k / 2)));
    }
    auto denom = choose(n, k);
    num = mul(num, mod_inverse(denom, MOD));
    num = add(num, 1);
    cout << num << endl;
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
