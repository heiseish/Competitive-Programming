/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 1e6 + 7;
using ll = long long;
ll a[N], r[5], f[N];
auto solve() -> void {
    ll n, d; cin >> n >> r[1] >> r[2] >> r[3] >> d; 
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = 2LL * (n - 1) * d  + min({r[1], r[2], r[3]}) * n
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}
