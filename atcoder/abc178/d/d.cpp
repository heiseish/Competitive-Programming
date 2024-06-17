/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 2e3 + 7;
const int MOD = 1e9 + 7;

int f[N], p[N];

int add(int a, int b) {
    a += b;
    a %= MOD;
    return a;
}
auto solve() -> void {
    int s; cin >> s;
    if (s < 3) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i <= s; ++i) {
        if (i >= 3) {
            f[i] = 1;
            f[i] = add(f[i], p[i - 3]);
        }
        p[i] = add(p[i-1], f[i]);
    }
    cout << f[s] << '\n';

}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
