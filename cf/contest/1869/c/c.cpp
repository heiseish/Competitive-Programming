/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
auto solve() -> void
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int shift = m - 1;
    int rem = max(0, n - shift);
    // debug(rem);
    for (int i = 0; i < rem; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = j;
        }
    }

    for (int i = rem; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = (i - rem + j) % m;
        }
    }

    vector<int> cols(m + 1, 0);
    for (int j = 0; j < m; ++j)
    {
        vector<bool> have(m + 1, false);
        for (int i = 0; i < n; ++i)
        {
            have[a[i][j]] = true;
        }
        for (int i = 0; i <= m; ++i)
        {
            if (!have[i])
            {
                cols[j] = i;
                break;
            }
        }
    }
    {
        vector<bool> have(m + 1, false);
        for (int i = 0; i < m; ++i)
        {
            have[cols[i]] = true;
        }
        int ans;
        for (int i = 0; i <= m; ++i)
        {
            if (!have[i])
            {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j] << ' ';
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
