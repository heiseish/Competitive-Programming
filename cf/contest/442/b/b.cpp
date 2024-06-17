/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 104;
using ld = long double;
ld a[N];

auto calc(vector<ld> a) -> ld
{
    ld ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        ld temp = a[i];
        for (int j = 0; j < a.size(); ++j)
        {
            if (i == j)
                continue;
            temp *= (1 - a[j]);
        }
        ans += temp;
    }
    return ans;
}
auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (a[n] >= 0.5)
    {
        cout << fixed << setprecision(10) << a[n] << endl;
        return;
    }
    ld ans = a[n];
    vector<ld> cur{a[n]};
    for (int i = n - 1; i >= 0; --i)
    {
        cur.emplace_back(a[i]);
        auto res = calc(cur);
        if (res > ans)
        {
            ans = res;
        }
        else
            break;
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
