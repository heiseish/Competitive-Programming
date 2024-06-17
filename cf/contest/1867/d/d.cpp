/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 1e5 + 7;
int b[N], can[N];
auto solve() -> void
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        can[i] = 0;
    }
    

    int s = accumulate(can + 1, can + 1 + n, 0);
    if (s == n)
        cout << "YES\n";
    else
        cout << "NO\n";
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
