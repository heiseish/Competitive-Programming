/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long double;
const int N = 2e5 + 7;
ll a[N];
char s[N], t[N];
ll f[50], b[50];
auto solve() -> void
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = a[i - 1] + (ll)i * i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i];
    }

    ll cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[(int)(t[i] - 'A')] += i;
        cnt += f[(int)(s[i] - 'A')] * (n - i + 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        cnt += b[(int)(t[i] - 'A')] * (n - i + 1);
        b[(int)(s[i] - 'A')] += i;
    }

    cout << fixed << setprecision(9) << (long double)1.0 * cnt / a[(int)n] << endl;
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
