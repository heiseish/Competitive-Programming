/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    auto s = accumulate(a.begin(), a.end(), 0);
    if (s < n)
    {
        cout << -1 << endl;
        return;
    }
    if (a[h - 1] == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (s == n)
    {
        cout << 1 << endl;
        return;
    }

    auto rem = s - a[h - 1];
    double ans = 1.0;
    auto tot = s - 1;
    for (int i = 2; i <= n; ++i)
    {
        ans *= 1.0 * rem-- / tot--;
    }
    cout << fixed << setprecision(6) << 1.0 - ans << endl;
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
