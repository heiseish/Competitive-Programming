/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto ans = max(a[0] - 0, l - a[n - 1]) * 2;
    for (int i = 1; i < n; ++i)
    {
        ans = max(ans, a[i] - a[i - 1]);
    }
    cout << fixed << setprecision(9) << 1.0 * ans / 2.0 << endl;
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
