/*
SOLUTION CODE

Code for problem E by cookiedoth
Generated 23 Feb 2019 at 02.32 P
 
 
▅███████ ]▄▄▄▄▄▄▄
█████████▅▄▃
Il████████████████]
◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤
 
~_^
=_=
¯\_(ツ)_/¯
 
*/
 
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
 
using namespace std;
 
template<class T> int chkmax(T &a, T b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}
 
template<class T> int chkmin(T &a, T b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
 
template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}
 
template<class T> void output(T x, ostream& out = cerr) {
    output(x.begin(), x.end(), out);
}
 
void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
const ll DEFAULT = -1e18;
 
struct st {
    vector<ll> t, len, sum, add_mod, set_mod;
    int n;
 
    void build(vector<ll> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = sum[v] = a[tl];
            len[v] = 1;
        }
        else {
            int tm = (tl + tr) >> 1;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
            sum[v] = sum[v * 2] + sum[v * 2 + 1];
            len[v] = (tr - tl + 1);
        }
    }
 
    st(vector<ll> &a) {
        n = a.size();
        t.resize(4 * n);
        sum.resize(4 * n);
        add_mod.resize(4 * n);
        set_mod.resize(4 * n, DEFAULT);
        len.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
 
    st() {}
 
    void apply_add_mod(int v, ll val) {
        if (set_mod[v] != DEFAULT) {
            set_mod[v] += val;
        }
        else {
            add_mod[v] += val;
        }
    }
 
    void apply_set_mod(int v, ll val) {
        add_mod[v] = 0;
        set_mod[v] = val;
    }
 
    void push(int v) {
        assert(add_mod[v] == 0 || set_mod[v] == DEFAULT);
        if (add_mod[v]) {
            t[v] += add_mod[v];
            sum[v] += add_mod[v] * len[v];
            apply_add_mod(v * 2, add_mod[v]);
            apply_add_mod(v * 2 + 1, add_mod[v]);
            add_mod[v] = 0;
        }
        if (set_mod[v] != DEFAULT) {
            t[v] = set_mod[v];
            sum[v] = set_mod[v] * len[v];
            apply_set_mod(v * 2, set_mod[v]);
            apply_set_mod(v * 2 + 1, set_mod[v]);
            set_mod[v] = DEFAULT;
        }
    }
 
    ll get_sum(int v) {
        if (set_mod[v] != DEFAULT) {
            return set_mod[v] * len[v];
        }
        if (add_mod[v]) {
            return add_mod[v] * len[v] + sum[v];
        }
        return sum[v];
    }
 
    ll get_t(int v) {
        if (set_mod[v] != DEFAULT) {
            return set_mod[v];
        }
        if (add_mod[v]) {
            return add_mod[v] + t[v];
        }
        return t[v];
    }
 
    void recalc(int v) {
        t[v] = max(get_t(v * 2), get_t(v * 2 + 1));
        sum[v] = get_sum(v * 2) + get_sum(v * 2 + 1);
    }
 
    void add_update(int l, int r, ll val, int v, int tl, int tr) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            apply_add_mod(v, val);
            return;
        }
        int tm = (tl + tr) >> 1;
        push(v);
        add_update(l, min(r, tm), val, v * 2, tl, tm);
        add_update(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
        recalc(v);
    }
 
    void set_update(int l, int r, ll val, int v, int tl, int tr) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            apply_set_mod(v, val);
            return;
        }
        int tm = (tl + tr) >> 1;
        push(v);
        set_update(l, min(r, tm), val, v * 2, tl, tm);
        set_update(max(l, tm + 1), r, val, v * 2 + 1, tm + 1, tr);
        recalc(v);
    }
 
    ll get_sum(int l, int r, int v, int tl, int tr) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return get_sum(v);
        }
        int tm = (tl + tr) >> 1;
        push(v);
        ll res_l = get_sum(l, min(r, tm), v * 2, tl, tm);
        ll res_r = get_sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
        return res_l + res_r;
    }
 
    int lower_bound(ll val, int v, int tl, int tr) {
        if (tl == tr) {
            return tl;
        }
        push(v);
        int tm = (tl + tr) >> 1;
        if (get_t(v * 2) >= val) {
            return lower_bound(val, v * 2, tl, tm);
        }
        else {
            return lower_bound(val, v * 2 + 1, tm + 1, tr);
        }
    }
 
    //interface
 
    void add_update(int l, int r, ll val) {
        add_update(l, r, val, 1, 0, n - 1);
    }
 
    void set_update(int l, int r, ll val) {
        set_update(l, r, val, 1, 0, n - 1);
    }
 
    ll get_sum(int l, int r) {
        ll res = get_sum(l, r, 1, 0, n - 1);
        return res;
    }
 
    int lower_bound(ll val) {
        if (get_t(1) < val) {
            return n;
        }
        else {
            return lower_bound(val, 1, 0, n - 1);
        }
    }
};
 
int n;
vector<ll> a, k, prefK, b;
 
signed main() {
    fast_io();
   
    cin >> n;
    a.resize(n);
    k.resize(n - 1);
    prefK.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> k[i];
    }
    for (int i = 1; i < n; ++i) {
        prefK[i] = prefK[i - 1] + k[i - 1];
    }
 
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - prefK[i];
    }
    st t(b), t1(prefK);
 
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;
        if (type == 's') {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << t.get_sum(l, r) + t1.get_sum(l, r) << '\n';
        }
        if (type == '+') {
            int pos;
            ll val;
            cin >> pos >> val;
            pos--;
            val += t.get_sum(pos, pos);
            int pos1 = t.lower_bound(val);
            t.set_update(pos, pos1 - 1, val);
        }
    }
}