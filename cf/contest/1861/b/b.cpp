/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == t[i] && s[i] == '0' && s[i + 1] == t[i + 1] && s[i + 1] == '1')
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
