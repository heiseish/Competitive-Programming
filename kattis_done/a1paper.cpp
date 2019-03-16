#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
	ll N;
	bool solvable = false;
	cin >> N;
	ld c = 0.0; 
	vector<ll> h(N-1, 0);
	vector<ll> n(N-1, 0);
	n[0] = 2;
	ld l=pow(2, -0.75), w=pow(2, -1.25);
	for (ll i = 0;i<N-1;i++) cin>>h[i];
	for (ll i = 0;i<N-1;i++ ){
		if (h[i] >= n[i]){
			c+=n[i]*l/2;
			solvable = true;
			break;
		}
		if (i == N-1) break;
		n[i+1]=(n[i]-h[i])*2;
		c+=n[i]*l/2;
		ld temp = l;
		l=w;
		w=temp/2;
	}
	if (solvable) cout << setprecision(15) << c << endl;
	else cout << "impossible" << endl;
	return 0;
}