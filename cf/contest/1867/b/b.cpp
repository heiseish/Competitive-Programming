/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 1e5 + 7;
char s[N];
auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    int diff = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
        diff += (int)(s[i] != s[n - i + 1]);
    }
    int same = n / 2 - diff;
    for (int i = 0; i <= n; ++i)
    {
        if (n % 2 == 0)
        {
            if (i >= diff && (i - diff) % 2 == 0 && i + diff <= n)
            {
                cout << 1;
                continue;
            }
        }
        else
        {
            if (i - 1 >= diff && (i - diff - 1) % 2 == 0 && i + diff <= n)
            {
                cout << 1;
                continue;
            }
            if (i >= diff && (i - diff) % 2 == 0 && i + diff <= n)
            {
                cout << 1;
                continue;
            }
        }
        cout << 0;
    }
    cout << '\n';
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
