/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 2e5 + 7;
using ll = long long;
ll a[N];
int h[60];
auto solve() -> void
{
    memset(h, 0, sizeof(h));
    int n;
    cin >> n;
    ll s = 0;
    // cerr << "-----------\n";
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % n != 0)
    {
        cout << "No\n";
        return;
    }
    ll avg = s / n;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == avg)
            continue;
        bool can = false;
        // debug(avg);
        // debug(a[i]);
        for (int j = 0; j <= 32; ++j)
        {
            ll nxt = a[i] + (1LL << j);
            ll rem = nxt - avg;
            // debug(a[i]);
            // debug(j);
            // debug(1LL << j);
            // debug(nxt);
            // debug(rem);
            if (rem <= 0)
                continue;
            ll aft = log2(rem);
            if (1LL << aft == rem)
            {
                // debug(avg);
                // debug(i);
                // debug(a[i]);
                // debug(j);
                // debug(aft);
                h[j]--;
                h[aft]++;
                can = true;
                break;
            }
        }
        if (!can)
        {
            // debug("cannot");
            cout << "No\n";
            return;
        }
    }
    for (int i = 0; i <= 32; ++i)
    {
        if (h[i] != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
