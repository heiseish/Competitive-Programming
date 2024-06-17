/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 1e5 + 7;
int a[N], f[N], s[2];
auto solve() -> void
{
    int n;
    cin >> n;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        int idx = (int)(c - '0');
        f[i] = a[i] ^ f[i - 1];
        s[idx] ^= a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int l, r;
            cin >> l >> r;
            int tr = f[r] ^ f[l - 1];
            s[0] ^= tr;
            s[1] ^= tr;
        }
        else
        {
            int zo;
            cin >> zo;
            cout << s[zo] << ' ';
        }
    }
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
