/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 4;
auto solve() -> void
{
    int n;
    cin >> n;

    unordered_map<int, vector<int>> r;
    r.reserve(N);
    double ans = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        r[a].emplace_back(i);
    }
    cerr << r.size() << endl;
    for (auto &[k, v] : r)
    {
        v.emplace_back(n + 1);
        double prob = 0.0;
        int sz = v.size();
        double szz = (long long)n * n;
        for (int i = -1; i < sz - 1; ++i)
        {
            if (i == -1)
            {
                prob += 1.0 * (v[i + 1] - 1) * (v[i + 1] - 1);
            }
            else
            {
                prob += 1.0 * (v[i + 1] - v[i] - 1) * (v[i + 1] - v[i] - 1);
            }
        }
        prob /= szz;
        prob = 1.0 - prob;
        ans += prob;
    }
    cout << fixed << setprecision(10) << ans << endl;
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
