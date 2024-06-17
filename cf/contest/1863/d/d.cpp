/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 507;
char s[N][N];
char ans[N][N];

auto solve() -> void
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> s[i][j];
            if (s[i][j] == '.')
            {
                ans[i][j] = '.';
            }
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         cerr << s[i][j];
    //     }
    //     cerr << '\n';
    // }

    for (int i = 1; i <= n; ++i)
    {
        int note = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == 'U')
            {
                note++;
            }
        }

        if (note % 2 == 1)
        {
            cout << -1 << '\n';
            return;
        }
        if (note == 0)
            continue;
        int cc = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (s[i][j] == 'U')
            {
                if (cc < note / 2)
                {
                    ans[i][j] = 'B';
                    ans[i + 1][j] = 'W';
                }
                else
                {
                    ans[i][j] = 'W';
                    ans[i + 1][j] = 'B';
                }
                cc++;
            }
        }
    }

    for (int j = 1; j <= m; ++j)
    {
        int note = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i][j] == 'L')
            {
                note++;
            }
        }

        if (note % 2 == 1)
        {
            cout << -1 << '\n';
            return;
        }
        if (note == 0)
            continue;
        int cc = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (s[i][j] == 'L')
            {
                if (cc < note / 2)
                {
                    ans[i][j] = 'B';
                    ans[i][j + 1] = 'W';
                }
                else
                {
                    ans[i][j] = 'W';
                    ans[i][j + 1] = 'B';
                }
                cc++;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << ans[i][j];
        }
        cout << '\n';
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
