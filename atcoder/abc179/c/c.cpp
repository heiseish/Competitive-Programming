/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
auto solve() -> void {
    int n; cin >> n;
    int64_t res = 0;
    for (int i = 1; i <= n; ++i) {
        res += n / i;
        if (n % i == 0) --res;
    }
    cout << res << '\n';
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
