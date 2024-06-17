/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " -> " << x << '\n'
using namespace std;
const int N = 1e5 + 7;
int a[N];
auto read() -> int
{
    int y;
    cin >> y;
    return y;
}
auto ans(int n) -> void
{
    cout << n << endl;
}
auto solve() -> void
{
    int n;
    cin >> n;
    bool has_zero = false, has_one = false;
    unordered_set<int> has;
    has.reserve(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        has.insert(a[i]);
        has_zero |= (a[i] == 0);
        has_one |= (a[i] == 1);
    }
    if (!has_zero && !has_one)
    {
        ans(0);
        auto _ = read();
        return;
    }
    int x = 0;
    while (has.find(x) != has.end())
        x++;

    while (true)
    {
        ans(x);
        auto nxt = read();
        if (nxt < 0)
        {
            return;
        }
        x = nxt;
    }
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
