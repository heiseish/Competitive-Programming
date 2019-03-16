#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> X(n + m);
	vector<int> isT(n + m);
	vector<ll> idx;
	for (ll i = 0; i < n + m; i++) scanf("%lld", &X[i]);
	for (ll i = 0; i < n + m; i++) {
		scanf("%d", &isT[i]);
		if (isT[i]) idx.push_back(i);
	}
	vector<ll> di(m, 0);
	ll cur = -1;
	ll i  = 0;
	while (!isT[i]){
		di[0]++;
		i++;
	}
	for (; i < n + m; i++) {
		if (isT[i]) {
			cur++;
			continue;
		}
		if (cur == m - 1) di[cur]++;
		else {
			if (X[i] - X[idx[cur]] <= X[idx[cur + 1]] - X[i]) di[cur]++;
			else di[cur + 1]++;
		}
	}
	for (auto i : di) printf("%lld ", i);
	printf("\n");
	return 0;
}