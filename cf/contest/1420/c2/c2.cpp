/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 3e5 + 7;
int64_t a[N];
using vi = vector<int64_t>;
using vvi = vector<vi>;
int n;
vvi f;
auto dp(int idx, int prev) -> int64_t {
    if (idx > n) return 0;
    if (f[prev + 1][idx] != -1) return f[prev + 1][idx];
    auto& ans = f[prev + 1][idx] = 0;
    
    if (prev == -1) ans = max(ans, a[idx] + dp(idx + 1, 0));
    if (prev == 0) ans = max(ans, -a[idx] + dp(idx + 1, -1));
    ans = max(ans, dp(idx + 1, prev)); // skip
    return ans;
}
auto solve() -> void {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    f.assign(2, vi(n + 1, -1));
    auto ini = dp(1, -1);
    cout << ini << '\n';
    set<int> sel;
    auto cur = ini;
    int now = -1;
    for (int i = 1; i <= n; ++i) {
        if (now == -1 && f[1][i + 1] + a[i] == cur) {
            sel.emplace(i);
            cur -= a[i];
            now = 0;
            continue;
        } 
        if (now == 0 && f[0][i + 1] - a[i] == cur) {
            sel.emplace(i);
            cur -= a[i];
            now = -1;
            continue;
        }
    }
    for (auto &v : sel) cerr << v << ' ';
    cerr << '\n';
    while (q--) {
        int l, r; cin >> l >> r;
    }
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}
