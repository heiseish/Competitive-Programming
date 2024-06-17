/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int p[N], c[N];
using ld = long double;
ld ans[N];
vector<int> g[N];

auto dfs0(int idx) -> int
{
    auto res = 1;
    for (const auto &v : g[idx])
    {
        res += dfs0(v);
    }
    c[idx] = res;
    return res;
}

auto dfs1(int idx) -> void
{
    auto tot = 0;
    for (const auto &v : g[idx])
        tot += c[v];

    int vv = g[idx].size();

    for (const auto &v : g[idx])
    {
        if (vv == 1)
        {
            ans[v] = ans[idx] + 1.0;
        }
        else
        {
            ld cur = tot - c[v];
            auto k = cur / (vv - 1);
            long long tmp = (long long)vv * (vv - 1);
            ans[v] = 1.0 * (vv * ans[idx] + (tmp / 2.0 * k) + vv) / vv;
        }

        dfs1(v);
    }
}

auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        cin >> p[i];
        g[p[i]].emplace_back(i);
    }
    c[1] = dfs0(1);
    ans[1] = 1.0;
    dfs1(1);
    cout << fixed << setprecision(6);
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
