/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " x << '\n'
using namespace std;

auto solve() -> void
{
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        if (a > 0)
            ans = min(ans, a);
        else
            ans = min(ans, -a);
    }
    cout << ans << '\n';
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
