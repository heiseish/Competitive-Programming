/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 2e5 + 7;
using pi = pair<int, int>;
pi a[N], b[N];
using ll = long long;
const ll INF = 1LL << 50;
struct Node {
    ll x, y;
    int idx = -1, idy = -1;
    Node(ll _x, ll _y) : x(_x), y(_y){}
    Node() : x(0), y(0) {}
};

ll st[N];
ll lazy[N << 2];
Node t[N << 2];

Node combine(Node lhs, Node rhs) {
    Node temp;
    temp.x = min(lhs.x, rhs.x);
    temp.y = max(lhs.y, rhs.y);
    return temp;
}


auto push(int v, int l, int r) -> void{
    t[v].x += lazy[v];
    t[v].y += lazy[v];
    if (l < r) {
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
    }
    lazy[v] = 0;
}
auto update(int v, int l, int r, int x, int y, ll to_add) -> void {
    push(v, l, r);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        lazy[v] += to_add;
        push(v, l, r);
        return;
    } 
    int mid = (l + r) >> 1;
    update(v << 1, l, mid, x, y, to_add);
    update(v << 1 |  1, mid+1, r, x, y, to_add);
    t[v] = combine(t[v << 1], t[v << 1 | 1]);
}
 
auto get(int v, int l, int r, int x, int y) -> Node {
    if (l > y || r < x) return {INF, -INF};
    push(v, l, r);
    if (l >= x && r <= y) return t[v];
    int mid = (l + r) >> 1;
    return combine(get(v << 1, l, mid, x, y), 
            get(v << 1 |  1, mid+1, r, x, y));
}
 

auto solve() -> void {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);

    ll best = 0;
    pi cur = {0, 0};
    
    update(1, 1, n, 1, 1, a[1].second);
    ll add = 0;
    vector<vector<ll>> track;
    for (int i = 2; i <= n; ++i) {
        auto x = a[i].first - a[i-1].first;
        auto y = a[i].second - a[i-1].second;

        add += x;
        update(1, 1, n, 1, i - 1, -y);
        auto top = get(1, 1, n, 1, i - 1);
        cerr << i << ' ' << top.x << ' ' << top.y << '\n';
        best = max(best, abs(top.x));
        best = max(best, abs(top.y));
        update(1, 1, n, 1, i - 1, y);
        update(1, 1, n, i, i, y);
    }
    cout << best << '\n';


}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
