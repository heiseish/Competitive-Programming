/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " x << '\n'
using namespace std;
const int N = 1e5 + 7;
const int MOD = 998244353;

int a[N], c[N];

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

    int n;
    cin >> n;

    unordered_map<int, int> exp;
    exp.reserve(n);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int b;
        cin >> b;
        exp[a[i]] = b;
    }
    int m;
    cin >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> c[i];
        if (exp.find(c[i]) == exp.end())
        {
            return void(cout << 0 << '\n');
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; ++i)
    {
        int d;
        cin >> d;
        if (exp[c[i]] < d)
        {
            return void(cout << 0 << '\n');
        }
        if (exp[c[i]] > d)
        {
            ans++;
        }
        exp.erase(c[i]);
    }
    for (const auto &[k, v] : exp)
    {
        ans++;
    }
    cout << bin_pow(2, ans) << '\n';
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
