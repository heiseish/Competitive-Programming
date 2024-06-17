/** 
If comrades that you trust gather around you, hope can take physical form and become visible. That’s what I believe.
*/
#include <bits/stdc++.h>
using namespace std;
/**
(▀̿Ĺ̯▀̿ ̿) (ง ͠° ͟ل͜ ͡°)ง
*/
const int N = 3e5 + 7;
using pi = pair<int, int>;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
public: 
	std::vector<int> ft; 
	int n;       

	FenwickTree(int _n) : n(_n) { ft.assign(n+1, 0); }    
	FenwickTree(const std::vector<int>& f) : n(f.size()-1) { ft.assign(n+1, 0);
    	for (int i = 1; i <= n; i++) {                      
    		ft[i] += f[i];                              
    		if (i+LSOne(i) <= n)  ft[i+LSOne(i)] += ft[i]; 
		} 
	}     
	int rsq(int j) {                         
   		int sum = 0; 
		for (; j; j -= LSOne(j)) sum += ft[j];
    	return sum; 
	}
	int rsq(int i, int j) { 
		return rsq(j) - rsq(i-1); 
	} 
  	void update(int i, int v) {
    	for (; i <= n; i += LSOne(i)) ft[i] += v; 
	} 

    int bit_search(int v, int bound) {
        int sum = 0;
        int pos = 0;
        int LOGN = log2(n) + 1;
        for(int i=LOGN; i>=0; i--) {
            if(pos + (1 << i) < bound and sum + ft[pos + (1 << i)] >= v) {
                sum += ft[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos;
    }
};

class RUPQ : public FenwickTree {  
public:
    RUPQ(int n) : FenwickTree(n) {}
    int point_query(int i) { return rsq(i); }
    void range_update(int i, int j, int v) { update(i, v), update(j+1, -v); }

  	int select(int k, int bound) {
    	int lo = 0, hi = bound;
    	for (int i = 0; i < 30; i++) { 
      		int mid = (lo+hi) / 2;             
      		(point_query(mid) >= k) ? lo = mid : hi = mid; 
		}
    	return lo; 
	}
    
};


auto solve() -> void {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    RUPQ ft(n);
    vector<pair<pi, int>> qu(q);
    for (int i = 0; i < q; ++i) {
        cin >> qu[i].first.second >> qu[i].first.first;
        qu[i].first.second++;
        qu[i].first.first = n - qu[i].first.first;
        qu[i].second = i;
    }
    vector<int> ans(q);
    sort(qu.begin(), qu.end());
    int cur_r = 1;
    for (auto &[ord, idx] : qu) {
        auto [r, l] = ord;
        // cerr << "pair is " << l << ' ' << r << '\n';
        while (r >= cur_r) {
            auto nxt = a[cur_r];
            if (nxt >= 0) {
                auto lmax = ft.bit_search(nxt, cur_r + 1);
                // cerr << "cur_r " << cur_r << ' ' << " lmax " <<  lmax << '\n';
                if (lmax > 0) ft.range_update(1, lmax, 1);
            }
            cur_r++;
        }
        ans[idx] = ft.point_query(l);
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}
auto main() -> int {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int tc = 1;
    while (tc--) {
        solve();
    }
    
    return 0;
}
