/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;

int ip(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return i;
    }
    return -1;
}
auto solve() -> void
{
    int l, r;
    cin >> l >> r;
    if (r <= 3)
    {
        cout << -1 << '\n';
        return;
    }

    if (r % 2 == 0)
    {
        cout << r / 2 << ' ' << r / 2 << '\n';
        return;
    }

    if (l != r)
    {
        cout << (r - 1) / 2 << ' ' << (r - 1) / 2 << '\n';
        return;
    }
    auto res = ip(l);
    if (res == -1)
        return void(cout << -1 << '\n');
    cout << res << ' ' << l - res << '\n';
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
