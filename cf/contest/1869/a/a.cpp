/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 105;
int a[N];
auto solve() -> void
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n % 2 == 0)
    {
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
        return;
    }
    cout << 4 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << n - 1 << ' ' << n << '\n';
    cout << n - 1 << ' ' << n << '\n';
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
