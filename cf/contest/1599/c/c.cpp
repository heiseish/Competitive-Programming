/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ld = long double;
auto solve() -> void
{

    ld n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i)
    {
        ld k = i;
        ld chance0 = (n - k) / n * (n - k - 1) / (n - 1.0) * (n - k - 2.0) / (n - 2.0);
        ld chance1 = k / n * (n - k) / (n - 1.0) * (n - k - 1.0) / (n - 2.0) * 3;
        ld res = (1.0 - chance1 - chance0) + (chance1 * 0.5);
        // cerr << (1.0 - chance1 - chance0) << ' ' << (chance1 * 0.5) << endl;
        if (res >= p)
        {
            cout << i << endl;
            return;
        }
    }
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
