/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " -> " << x << '\n'
const int N = 2e5 + 7;
int a[N];
auto solve() -> void
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (i > 1 && a[i] <= a[i - 1])
            cnt++;
    }
    auto ans = n;
    auto cnt2 = 0;
    for (int i = 0; i <= n; ++i)
    {
        // debug(i);
        // debug(cnt);
        // debug(cnt2);
        int addone = (i > 0);

        if (i > 0 && i < n)
        {
            if (a[i] >= a[i + 1])
                cnt--;
        }
        ans = min(ans, addone + cnt + cnt2);
        if (i > 0 && i < n)
        {
            if (a[i] <= a[i + 1])
                cnt2++;
        }
    }
    // debug(cnt);
    // debug(cnt2);
    // cerr << "-------------\n";
    cout << ans << '\n';
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
