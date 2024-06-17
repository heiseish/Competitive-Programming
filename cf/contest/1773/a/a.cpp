/**
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N], c[N];
vector<int> perm(N);

auto check(const vector<int> &v) -> bool
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == i + 1)
            return false;
    }
    return true;
}

auto check(int n) -> bool
{
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == i)
            return false;
    }
    return true;
}

auto compute(int n) -> void
{
    for (int i = 1; i <= n; ++i)
    {
        cerr << "i = " << i << endl;
        cerr << "b[i] = " << b[i] << endl;
        cerr << "perm[i - 1] = " << perm[i - 1] << endl;
        c[perm[i - 1]] = b[i];
    }
}
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
auto solve() -> void
{
    int n;
    cin >> n;
    perm.clear();

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[a[i]] = i;
        perm.emplace_back(i);
    }
    for (auto _ = 0; _ <= 700; ++_)
    {
        shuffle(perm.begin(), perm.end(), rng);

        if (!check(perm))
        {
            continue;
        }

        compute(n);
        if (!(check(n)))
        {
            continue;
        }

        cout << "Possible\n";

        for (int i = 1; i <= n; ++i)
            cout << c[i] << ' ';
        cout << '\n';
        for (const auto &v : perm)
            cout << v << ' ';
        cout << '\n';
        return;
    }
    cout << "Impossible\n";
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
