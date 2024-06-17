/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    string s, t;
    cin >> s >> t;
    auto idx = 20;
    for (const auto &ch : s)
    {
        if (ch == '+')
            idx++;
        else
            idx--;
    }
    double a[50][50];
    bool vis[50][50];
    a[20][0] = 1.0;
    queue<pair<int, int>> q;
    q.emplace(20, 0);
    while (!q.empty())
    {
        const auto &f = q.front();
        q.pop();

        auto nxt = f.second + 1;
        if (nxt > s.size())
            continue;
        if (vis[f.first][f.second])
            continue;
        vis[f.first][f.second] = true;
        const auto &ch = t[f.second];
        const auto &current_prob = a[f.first][f.second];
        if (ch == '+')
        {
            a[f.first + 1][nxt] += current_prob;
            q.emplace(f.first + 1, nxt);
        }
        else if (ch == '-')
        {
            a[f.first - 1][nxt] += current_prob;
            q.emplace(f.first - 1, nxt);
        }
        else
        {
            a[f.first + 1][nxt] += 0.5 * current_prob;
            a[f.first - 1][nxt] += 0.5 * current_prob;
            q.emplace(f.first + 1, nxt);
            q.emplace(f.first - 1, nxt);
        }
    }
    cout << fixed << setprecision(9) << a[idx][s.size()] << endl;
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
