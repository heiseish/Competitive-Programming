/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
#define debug(x) cerr << #x << "  ->> " << x << endl
auto solve() -> void {
    int64_t n, x, m; cin >> n >> x >> m;
    int64_t res = x, ct = 1LL, last = x;

    vector<int64_t> so_far(m);
    deque<int64_t> seq; seq.emplace_back(x);
    so_far[x]++;
    while (ct < n) {
        ++ct;
        last = (last * last) % m;
        res += last;
        // debug(last);
        seq.emplace_back(last);
        if (so_far[last]++) {
            // found cycle
            break;
        }
        
    }
    if (ct < n) {

        // for (auto &v : seq) cerr << v << ' ';
        // cerr << '\n';
        while (seq.front() != last) seq.pop_front();
        seq.pop_front();
        // debug((int64_t) seq.size());
        auto cyc_tot = accumulate(seq.begin(), seq.end(), 0LL);
        int64_t left = n - ct;
        int64_t cyc_left = left / (int64_t) seq.size();
        res += cyc_left * cyc_tot;
        ct += cyc_left * (int64_t) seq.size();
        // debug(res);
        // debug(ct);
        int now = 0;
        while (ct < n) {
            res += seq[now++];
            ++ct;
        }
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
