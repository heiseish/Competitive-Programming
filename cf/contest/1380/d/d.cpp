/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 2e5  +7;
ll a[N], b[N];
using pi = pair<int, int>;
using ll = long long;
auto solve() -> void {
    int n, m; cin >> n >> m;
    int x, k, y; cin >> x >> k >> y;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    int cur = 1;
    vector<pi> res;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        pi ends{cur, -1};
        while (cur <= n && a[cur] != b[i]) ++cur;    
        if (cur > n) {
            cout << -1 << '\n';
            return;
        }
        ends.second = cur;
        if (ends.second != ends.first) res.emplace_back(ends);
    }
    ll ans = 0;
    for (auto &v : cur) {
        // maximize 
    }
    cout << ans << '\n';

}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
