/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    string s;
    cin >> s;
    bool three = false, one = false;
    for (const auto &ch : s)
    {
        if (ch == '3')
        {
            three = true;
            break;
        }
        if (ch == '1')
        {
            one = true;
            break;
        }
    }
    if (one)
    {
        cout << 13 << endl;
    }
    else
    {
        cout << 31 << endl;
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
