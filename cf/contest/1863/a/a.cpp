/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    int n, a, q;
    cin >> n >> a >> q;

    int cum = 0, cc = 0;
    int hi = a;
    for (int i = 1; i <= q; ++i)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            ++cum;
            ++cc;
        }
        else
        {
            --cc;
        }
        hi = max(hi, a + cc);
    }
    if (a + cum < n)
    {
        cout << "NO\n";
    }
    else if (hi == n)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "MAYBE\n";
    }
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
