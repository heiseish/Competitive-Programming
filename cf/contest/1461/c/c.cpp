/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    auto idx = n - 1;
    for (; idx >= 0; idx--)
    {
        if (a[idx] != idx + 1)
            break;
    }
    double ans;
    if (idx == -1)
    {
        ans = 1.0;
    }
    else
    {
        ans = 0;
    }
    for (int i = 0; i < m; ++i)
    {
        int r;
        double p;
        cin >> r >> p;
        r--;

        if (r < idx)
            continue;

        ans = p + ans * (1.0 - p);
    }
    cout << ans << endl;
}
auto main() -> int
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
