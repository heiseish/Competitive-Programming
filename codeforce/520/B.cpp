#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is(ll n) {
	if (n%2==0) return false;
	for (ll i = 3; i * i <= n;i+=2) {
		if (n%i==0) return false;
	}
	return true;
}

int main() {
	ll n;
	scanf("%lld", &n);
	unordered_map<ll, ll> p;
	ll d = 2;
	ll MAX = -1;
	if (is(n)) {
		printf("%lld 0\n", n);
		exit(0);
	}
	int res = 1;
	while (n >= d) {
		if (n % d != 0) d++;
		else {
			while(n%d == 0) {
				if (p.find(d) == p.end()) p[d] = 1;
				else p[d]++;
				n/=d;
			}
			res *= d;
			if (p[d] > MAX) MAX = p[d];
			d++;
		}
	}
	int ct = 0;
	int x = 1;
	while(x < MAX) {
		x*=2;
		ct++;
	}
	int wtf = 0;
	for (auto i : p) {
		if (i.second != x) wtf = 1;
	}
	printf("%d %d\n", res, ct + wtf);
	
	return 0;
}