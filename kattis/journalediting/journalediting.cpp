#include <bits/stdc++.h>
using namespace std;
#define vvv vector<vector<vector<ll> > >
#define vv vector<vector<ll> >
typedef long long ll;

// ll inf = 1 << 30;
// ll  inf  = 1 << 30;
const ll inf = numeric_limits<ll>::max();

vector<ll> lengths;
vvv theorems;
vv rawLength;


ll scanThrough(vector<ll>& currentWorking, ll index) {
	if (lengths[index] != -1) return lengths[index];

	currentWorking[index] = 1;
	ll min = inf;
	vector<ll> result = currentWorking;
	for (ll i = 0; i < theorems[index].size(); i++) {
		vector<ll> proof = theorems[index][i];
		ll singleProofLength = rawLength[index][i];
		vector<ll> currentWorkingTemp = currentWorking;
		for (auto j : proof) {
			if (currentWorkingTemp[j] == 1) {
				singleProofLength = inf;
				break;
			}
			if (currentWorkingTemp[j] == 2) continue;
			scanThrough(currentWorkingTemp, j);
			if (lengths[j] == inf) {
				singleProofLength = inf;
				break;
			}
			singleProofLength += lengths[j];
		
		}
		if (singleProofLength < min) {
			result = currentWorkingTemp;
			min = singleProofLength;
		}
	}
	currentWorking = result;
	currentWorking[index] = 2;
	return lengths[index] = min;
	// return min;
}
int main() {
	ll n;
	cin >> n;
	
	lengths = vector<ll>(n, -1);
	//construct graph
	for (ll i = 0; i < n; i++) {
		ll p;
		cin >> p;
		vv t1;
		vector<ll> t;
		theorems.push_back(t1);
		rawLength.push_back(t);
		for (ll j = 0; j < p; j++) {
			ll l;
			ll k;
			cin >> l >> k;
			rawLength[i].push_back(l);
			vector<ll> t2;
			theorems[i].push_back(t2);
			for (ll z = 0; z < k; z++) {
				ll t3;
				cin >> t3;
				theorems[i][j].push_back(t3);
			}
		}
	}
	vector<ll> currentWorking(n, 0);
	cout << scanThrough(currentWorking, 0) << endl;
	return 0;
}