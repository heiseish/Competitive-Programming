/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 1e6 + 5;
ll inv[N];
vector<int> a[N];
int b[N];
ll add(ll a, ll b)
{
    a += b;
    a %= MOD;
    if (a < MOD)
        a += MOD;
    return a % MOD;
}
ll mul(ll a, ll b)
{
    return a * b % MOD;
}

ll bin_pow(ll a, ll b)
{
    a %= MOD;
    ll ret = 1;
    while (b)
    {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y)
{
    ll xx = y = 0;
    ll yy = x = 1;
    while (b)
    {
        ll q = a / b;
        ll t = b;
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

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

auto precal_inv() -> void
{
    inv[1] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = add(MOD, -mul((MOD / i), inv[MOD % i]));
}

ll mod_inverse(ll b, ll m)
{
    ll x, y;
    ll d = extended_euclid(b, m, x, y);
    if (d != 1)
        return -1;
    return add(x, 0);
}

auto solve() -> void
{
    // precal_inv();
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        a[i].reserve(k);
        for (int j = 0; j < k; ++j)
        {
            int ai;
            cin >> ai;
            a[i].emplace_back(ai);
            b[ai]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ll num = 0;
        for (const auto &ai : a[i])
        {
            num += b[ai];
        }
        ll denom = n * n * (ll)a[i].size();
        auto com = gcd(num, denom);
        num /= com;
        denom /= com;
        ans = add(ans, mul(num, mod_inverse(denom, MOD)));
    }
    cout << ans << endl;
    // cout << mul(7, mod_inverse(8, MOD)) << endl;
}
auto main() -> int
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}
