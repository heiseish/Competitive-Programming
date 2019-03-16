#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<iii> viii;
typedef vector<bool> vb;
typedef unordered_map<ll, viii> um;
typedef long long ll;
const ll maxn = 3e5 + 10;
ll inf = 1LL << 60;

ii p[maxn];
bool v[maxn] = { false };
vector<ii>T[maxn];
ll ct = 0;
ll n, m, k;
um g, dt;
vi res;

void djikstra(ll s) {
	ll dist[maxn];
	for(int i = 1; i<= n; i++) dist[i] = inf;
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	q.push({ 0, s}) ;
	while(!q.empty()) {
		ii tt = q.top();
		q.pop();
		if (v[tt.second]) continue;
		v[tt.second] = true;
		if (p[tt.second].first > 0) T[p[tt.second].first].push_back({ tt.second, p[tt.second].second});

		for (auto i : g[tt.second]) {
			ll idx = i.second.first;
			if (dist[idx] > dist[tt.second] + i.first) {
				p[idx] = { tt.second, i.second.second };
				dist[idx] = dist[tt.second] + i.first;
				q.push({ dist[idx], idx });
			}
		}
	}
}

void dfs(ll index) {
	for (auto i : T[index]) {
		if (res.size() < k) res.push_back(i.second);
		dfs(i.first);
	}
}

int main() {

	scanf("%lld %lld %lld", &n, &m, &k);
	for (ll i = 1; i <= m; i++) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		g[u].push_back({ w , { v, i }});
		g[v].push_back({ w , { u, i }});
	}
	djikstra(1);
	dfs(1);
	printf("%ld\n", res.size());
	for (auto i : res) printf("%lld ", i);
	printf("\n");
	return 0;
}