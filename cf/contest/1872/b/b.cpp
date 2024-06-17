/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;

auto solve() -> void
{
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int d, s;
        cin >> d >> s;
        ans = min(ans, d + (int)ceil(1.0 * s / 2.0) - 1);
    }
    cout << ans << '\n';
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
