/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
using ll = long long;
ll h[N], dp[N];
vector<int> f[N], g[N];
ll k;
int topo[N];
bool visited[N];
vector<int> topo_ordered(N);

auto dfs(int v) -> void
{
    visited[v] = true;
    for (int u : g[v])
    {
        if (!visited[u])
            dfs(u);
    }
    topo_ordered.push_back(v);
}

auto dfs(int st, ll &ans) -> void
{
    ans = max(ans, dp[st] * k + h[st]);
    for (const auto &v : g[st])
    {
        if (dp[v] * k + h[v] < dp[st] * k + h[st])
        {
            dp[v] = max(dp[v], dp[st] + (h[v] >= h[st] ? 0 : 1));
            dfs(v, ans);
        }
    }
}

struct by_h
{
    inline bool operator()(const int &lhs, const int &rhs)
    {
        return h[lhs] > h[rhs];
    }
};

struct by_topo
{
    inline bool operator()(const int &lhs, const int &rhs)
    {
        return topo[lhs] < topo[rhs];
    }
};

auto solve() -> void
{
    ll n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        dp[i] = -1;
        f[i].clear();
        g[i].clear();
        visited[i] = false;
    }

    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        f[b].emplace_back(a);
    }

    topo_ordered.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo_ordered.begin(), topo_ordered.end());
    for (int i = 1; i <= n; ++i)
    {
        topo[topo_ordered[i - 1]] = i;
    }
    vector<int> qq;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i].empty())
        {
            dp[i] = 0;
            qq.emplace_back(i);
        }
    }
    sort(qq.begin(), qq.end(), by_h());

    ll ans = 0;
    for (const auto &idx : topo_ordered)
    {
        for (const auto &v : f[idx])
        {
            dp[idx] = max(dp[idx], dp[v] + (h[idx] >= h[v] ? 0 : 1));
        }
        ans = max(ans, dp[idx] * k + h[idx]);
    }
    ll real_ans = ans;
    while (!qq.empty())
    {
        vector<int> temp;
        auto va = qq.back();
        qq.pop_back();
        temp.emplace_back(va);
        while (!qq.empty() && h[qq.back()] == h[va])
        {
            auto vv = qq.back();
            qq.pop_back();
            temp.emplace_back(vv);
        }
        real_ans = min(ans - h[va], real_ans);
        for (const auto &vv : temp)
            dp[vv]++;
        for (const auto &vv : temp)
            dfs(vv, ans);
    }
    cout << real_ans << '\n';
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