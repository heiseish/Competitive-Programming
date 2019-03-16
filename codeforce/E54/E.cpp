#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int p[maxn] = { 0 };
ll s[maxn] = { 0L };
ll d;
unordered_map<ll, vector<ll> > g, rg;
void DFS(int index, ll k, ll x) {
	if (k == 0) return;
	for (auto i : rg[index]) {
		s[i] += x;
		DFS(i, k - 1, x);
	}
}

bool v[maxn] = { false };
void formTree(int index) {
	v[index] = true;
	for (auto i : g[index]) {
		if (!v[i]) {
			rg[index].push_back(i);
			formTree(i);
		}
		
	}
}

int main() {
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	formTree(1);

	ll m;
	scanf("%lld", &m);
	while(m--) {
		ll v, d, x;
		scanf("%lld %lld %lld", &v, &d, &x);
		s[v] += x;
		DFS(v, d, x);
	}
	for (int i = 1; i <= n; i++) printf("%lld ", s[i]);
	printf("\n");
	return 0;
}