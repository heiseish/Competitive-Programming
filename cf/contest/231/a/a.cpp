/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;

auto solve() -> void {
    int n; cin >> n;
    auto ans = 0;
    while (n--) {
        int a, b, c;
        cin >> a  >> b >> c;
        ans += ((a + b + c) >= 2);   
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
