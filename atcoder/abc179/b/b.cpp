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
    vector<pair<int, int>> a(n);
    int last = -1;
    int ct = 0;
    bool can = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first != a[i].second) {
            ct = 0;
        } else {
            ct++;
        }
        if (ct >= 3) can = true;
    }
    if (can) cout << "Yes\n";
    else cout << "No\n";
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
