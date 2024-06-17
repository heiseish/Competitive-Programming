/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int MOD = 998244353;
const int N = 2e5 + 7;
using pi = pair<int, int>;
pi a[N];
int f[N], p[N];
int add(int a, int b) {
    a += b;
    if (a < MOD) a += MOD;
    return a % MOD;
}


auto solve() -> void {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; ++i) cin >> a[i].first >> a[i].second;
    f[n] = 1; p[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= k; ++j) {
            auto l = i + a[j].first;
            auto r = min(n, i + a[j].second);

            if (l > r) continue;
            f[i] = add(f[i], add(p[l], -p[r + 1]));
        }
        p[i] = add(p[i + 1], f[i]);
    }
    cout << f[1] << '\n';
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
