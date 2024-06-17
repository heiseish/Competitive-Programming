/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    long double a, b;
    cin >> a >> b;
    swap(a, b);

    if (a == 0)
    {
        cout << 1.0 << endl;
        return;
    }

    if (b == 0)
    {
        cout << 0.5 << endl;
        return;
    }

    auto area = a * b;
    if (a >= b / 4)
    {
        auto smol = (a - b / 4) * b;
        auto prob = (area - smol) / 2;
        auto ans = 0.5 + 0.5 * prob / area;
        cout << ans << endl;
        return;
    }
    auto other = a * 4 * a / 2;
    auto ans = 0.5 + 0.5 * (area - other) / area;
    cout << ans << endl;
}
auto main() -> int
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
