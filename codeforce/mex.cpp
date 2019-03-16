#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	cin >> n;
	ll max = -1, w=-1;
	bool found = false;
	for(ll i =1;i<=n;i++) {
		ll temp;
		cin >> temp;
		if (temp > max + 1 && !found) {
			w = i;
			found = true;
		}
		if (temp == max + 1) {
			max = temp;
		}
	}
	cout << w << endl;
	return 0;
}