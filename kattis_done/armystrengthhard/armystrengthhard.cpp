#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int maxn = 0, maxm = 0;
		while(n--){
			int temp;
			cin >> temp;
			if (temp > maxn) maxn = temp;
		}
		while(m--){
			int temp;
			cin >> temp;
			if (temp > maxm) maxm = temp;
		}
		cout << (maxn >= maxm ? "Godzilla" : "MechaGodzilla") << endl;  
	}
	return 0;
}