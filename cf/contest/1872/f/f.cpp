/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
bool vis[N];
int par[N], c[N], a[N];

auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        vis[i] = false;
        par[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        par[a[i]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    deque<int> ans;

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            // do search
            map<int, int> track;
            vector<int> q;
            int cur = i;
            vis[cur] = true;
            q.emplace_back(cur);
            track[cur] = q.size() - 1;

            while (!vis[a[cur]])
            {
                cur = a[cur];
                vis[cur] = true;
                q.emplace_back(cur);
                track[cur] = q.size() - 1;
            }
            if (track.find(a[cur]) != track.end())
            {
                // cycle
                int st = track[a[cur]];
                int mm = c[q[st]];
                int midx = st;
                for (int i = st + 1; i < q.size(); ++i)
                {
                    if (c[q[i]] < mm)
                    {
                        mm = c[q[i]];
                        midx = i;
                    }
                }
                for (int i = midx; i >= st; --i)
                {
                    ans.emplace_front(q[i]);
                }
                for (int i = (int)q.size() - 1; i > midx; --i)
                {
                    ans.emplace_front(q[i]);
                }
                for (int i = st - 1; i >= 0; --i)
                {
                    ans.emplace_front(q[i]);
                }
            }
            else
            {
                for (int i = (int)q.size() - 1; i >= 0; --i)
                {
                    ans.emplace_front(q[i]);
                }
            }
        }
    }

    for (const auto &v : ans)
        cout << v << ' ';
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
