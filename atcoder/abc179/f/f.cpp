/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 2e5 + 7;
int64_t cross[3][N];
int64_t track[3][N];
set<int64_t> now[3];
#define debug(x) cerr << #x << "  ->> " << x << endl
auto solve() -> void {
    int64_t n; cin >> n;
    int64_t res = (n  - 2) * (n - 2);

    int q; cin >> q;
    while (q --) {
        int query, idx; cin >> query >> idx; --query;
        if (cross[query][idx]++) continue;
        auto &dir = now[query];
        auto prev = dir.lower_bound(idx);
        int reduce = -1;
        if (prev != dir.begin()) {
            --prev;
            // closest smallest
            reduce = track[query][*prev];
        } else {
            if (now[query ^ 1].empty()) {
                reduce = n - 2;
                // strike all
            } else {
                // strike the smallest from opposite
                // debug(*now[query ^ 1].begin());
                reduce = *now[query ^ 1].begin() - 2;
            }  
        }
        // debug(query);
        // debug(idx);
        // debug(reduce);
        res -= reduce;
        assert(reduce > -1);
        track[query][idx] = reduce;
        dir.emplace(idx);
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
