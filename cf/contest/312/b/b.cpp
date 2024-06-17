/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    auto f1 = a / b;
    auto f2 = c / d;
    cout << fixed << setprecision(12) << f1 / (1 - (1 - f1) * (1 - f2)) << endl;
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
