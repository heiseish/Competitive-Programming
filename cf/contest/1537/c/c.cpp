/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N];
auto solve() -> void {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);

    if (n == 2) {
        for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
        return;
    }

    map<int, int> t;
    int min_diff = 1 << 30;
    int min_idx = -1;
    for (int i = 1; i <= n; ++i) {
        t[a[i]]++;
        if (i < n && a[i + 1] - a[i] < min_diff) {
            min_diff = a[i + 1] - a[i];
            min_idx = i;
        }
    }
    // all distinct height
    for (int i = min_idx + 1; i <= n; ++i) cout << a[i] << ' ';
    for (int i = 1; i <= min_idx; ++i) cout << a[i] << ' ';
    cout << '\n';
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    
    return 0;
}
