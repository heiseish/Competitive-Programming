/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() -> void
{
    ll k; // = 0b111111111111111110LL;
    cin >> k;
    if (k % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> res;
    for (ll i = 1; i < 64; ++i)
    {
        if (((1LL << i) & k) == 0)
            continue;

        if (i > 1)
        {
            res.emplace_back(1);
            for (ll j = 1; j <= i - 2; ++j)
            {
                res.emplace_back(0);
            }
        }

        res.emplace_back(1);
    }
    cout << res.size() << '\n';
    for (const auto &v : res)
        cout << v << ' ';
    cout << '\n';
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
