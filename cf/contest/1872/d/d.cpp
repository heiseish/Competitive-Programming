/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
using ll = long long;
auto gcd(ll a, ll b) -> ll
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
auto lcm(ll a, ll b) -> ll
{
    return a / gcd(a, b) * b;
}
auto solve() -> void
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll d = lcm(x, y);
    ll best = n / x - n / d;
    ll worst = n / y - n / d;
    cout << best * n - (best - 1) * best / 2 - worst * (worst + 1) / 2 << '\n';
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
