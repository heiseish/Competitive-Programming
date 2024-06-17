/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

auto solve() -> void
{
    int n, a;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (s.empty())
        {
            s.emplace(a);
        }
        else
        {
            if (s.find(a - 1) == s.end())
            {
                s.emplace(a);
            }
            else
            {
                s.erase(a - 1);
                s.emplace(a);
            }
        }
    }
    cout << s.size() - 1 << endl;
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
