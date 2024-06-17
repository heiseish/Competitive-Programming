/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    string s;
    cin >> s;
    int idx = 0;
    int sup = INT_MAX;
    int lsp = 0;
    for (const auto &ch : s)
    {
        if (ch == '+')
        {
            idx++;
        }
        else if (ch == '-')
        {
            if (lsp == idx)
                lsp--;
            if (sup == idx)
            {
                sup = INT_MAX;
            }
            idx--;
        }
        else if (ch == '1')
        {
            lsp = idx;
            if (sup <= idx)
            {
                return void(cout << "NO\n");
            }
        }
        else if (ch == '0')
        {
            if (idx < 2)
            {
                cout << "NO\n";
                return;
            }
            sup = min(idx, sup);
            if (lsp >= idx)
            {
                return void(cout << "NO\n");
            }
        }
    }
    cout << "YES\n";
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
