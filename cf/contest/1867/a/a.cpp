/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 1e5 + 7;
int ans[N];
auto solve() -> void
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        ans[a[i].second] = n - i;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
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
