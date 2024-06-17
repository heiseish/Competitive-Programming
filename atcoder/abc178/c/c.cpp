/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int MOD = 1e9 + 7;
using ll = long long;
ll add(ll a, ll b) {
    a += b;
    a %= MOD;
    if (a < 0) a += MOD;
    a %= MOD;
    return a;
}
ll mul(ll a, ll b) {
    return a * b % MOD;
}

auto fastpow(ll a, ll b) -> ll {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = mul(ret, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}


auto solve() -> void {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    auto res = fastpow(8, n);
    auto s = add(fastpow(9, n), -fastpow(8, n));
    res = add(res, mul(2, s));
    res = add(fastpow(10, n), -res);
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
