/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " -> " << x << '\n'
const int N = 1e4 + 6;
using ll = unsigned long long;
ll a[N], mask_start[N], mask_end[N], cumxor[N];
bool can[N][N];
int fastb[N], fastf[N];
auto solve() -> void
{
    int n;
    cin >> n;
    cumxor[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        cumxor[i] = a[i] ^ cumxor[i - 1];
        mask_start[i] = 0;
        mask_end[i] = 0;
        fastf[i] = -1;
        fastb[i] = INT_MAX;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            can[i][j] = false;
        }
    }
    can[1][n] = true;

    for (int len = n; len >= 1; --len)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i + len - 1 > n)
            {
                break;
            }

            int l = i;
            int r = i + len - 1;
            ll s = cumxor[r] ^ cumxor[l - 1];
            can[l][r] |= (fastf[l] >= r);
            can[l][r] |= (fastb[r] <= l);
            can[l][r] |= ((s & mask_start[l]) > 0 || (s & mask_end[r]) > 0);
            if (!can[l][r])
                continue;
            if (s == 0)
            {
                fastf[l] = max(fastf[l], r);
                fastb[r] = min(fastb[l], l);
            }
            else
            {
                mask_start[l] |= (1ULL << (63 - __builtin_clzll(s)));
                mask_end[r] |= (1ULL << (63 - __builtin_clzll(s)));
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << (can[i][i] ? '1' : '0');
    cout << '\n';
    // cerr << "---------------\n";
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
