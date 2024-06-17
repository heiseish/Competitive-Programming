/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int l[N], r[N];
auto solve() -> void
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
    }

    double ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto tot1 = r[i] - l[i] + 1;
        auto p1 = r[i] / p - (l[i] - 1) / p;
        auto np1 = tot1 - p1;
        auto f1 = 1.0 * np1 / tot1;

        auto nxt = i == n ? 1 : i + 1;
        auto tot2 = r[nxt] - l[nxt] + 1;
        auto p2 = r[nxt] / p - (l[nxt] - 1) / p;
        auto np2 = tot2 - p2;
        auto f2 = 1.0 * np2 / tot2;

        // cerr << p1 << ' ' << p2 << endl;
        // cerr << np1 << ' ' << np2 << endl;
        // cerr << f1 << ' ' << f2 << endl;
        ans += (1.0 - f1 * f2);
    }
    ans *= 2000;

    cout << fixed << setprecision(6) << ans << endl;
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
