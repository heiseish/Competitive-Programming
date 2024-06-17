/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 2e5 + 7;
using ll = long long;
ll a[N];

auto get(ll x) -> int
{
    ll aft = log2(x);
    if (1LL << aft == x)
    {
        return aft;
    }
    return -1;
}
auto solve() -> void
{
    int n;
    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    vector<vector<int>> f(n, vector<int>(n + 1, -1));
    if (s % n != 0)
    {
        cout << "No\n";
        return;
    }
    ll avg = s / n;
    for (int i = 1; i <= n; ++i)
    {
        ll diff = abs(a[i] - avg);
        ll single = get(diff);
        if (single != -1)
        {
        }
    }
    for (int i = 0; i <= 32; ++i)
    {
        if (h[i] != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
