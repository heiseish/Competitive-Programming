#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;

int main() {
	ll n,m,l;
	scanf("%lld %lld %lld", &n, &m, &l);
	vector<ll> h(n);
	vector<ii> ltl;
	ll start = -1, end = -1;
	ll MAX = -1;
	for (ll i = 0; i < n; i++)  {
		scanf("%lld", &h[i]);
		if (h[i] <= l && start != -1) {
			ltl.push_back({ start, end });
			start = end = -1;
		}
		else if (h[i] > l) {
			if (start == -1) start = end = i;
			else end = i;
		}
	}
	if (start != -1) ltl.push_back({ start, end });
	while(m--) {
		ll q;
		scanf("%lld", &q);
		if (!q) {
			printf("%ld\n", ltl.size());
			// for (auto i : ltl) {
			// 	cout << i.first << " " << i.second << endl;
			// }
		} else {
			ll p, d;
			scanf("%lld %lld", &p, &d);
			ll temp = h[p - 1];
			h[p - 1] += d;
			
			if (temp <= l && h[p - 1] > l) {
				if (p - 1 > 0 && p - 1 < n - 1 && h[p] > l && h[p-2]>l) {
					ll td = -1, tc = -1, cc= -1;
					for (ll i = 0 ; i < ltl.size(); i++) {
						if (ltl[i].second == p - 2) {
							tc = i;
						}
						if (ltl[i].first == p) {
							td = i;
							cc = ltl[i].second;
						}
					}
					ltl[tc].second = cc;
					ltl.erase(ltl.begin() + td);
				} else if (p - 1 < n - 1 && h[p] > l) {
					for (auto& i : ltl) {
						
						if (i.first == p) i.first = p -  1;
					}
				} else if (p - 1 > 0 && h[p - 2] > l) {
					for (auto& i : ltl) {
						
						if (i.second == p - 2) i.second = p - 1;
					}
				} else {
					ltl.push_back({ p - 1, p - 1});
				}
			}
		}
	}
	return 0;
}