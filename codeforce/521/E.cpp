#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int inf = 1 << 30;
/**
Start coding from here
*/
const int maxn = 2e5 + 7;
int s[maxn];
int main() {
	int n;
	scanf("%d", &n);
	map<int, int> dp;
	forn(i, 0, n - 1) {
		scanf("%d", &s[i]);
		dp[s[i]]++;
	}
	vi arr;
	for (auto i : dp) arr.push_back(i.second);
	sort(arr.begin(), arr.end(), greater<int>());
	vll res;
	ll s = 0;
	ll MAX = 0;
	forn(i, 0, arr.size() - 1) {
		if (i == 0) s += arr[0];
		else {
			if (arr[i] <= arr[i - 1]/2) {
				s = arr[i] * (pow(2, i + 1) - 1);
			} else {
				if (arr[i - 1] %2 != 0) {
					arr[i - 1]--;
					arr[i] = arr[i - 1]/2;
					s = arr[i] * (pow(2, i + 1) - 1);
				} else {
					arr[i] = arr[i - 1]/2;
					s += arr[i];
				}
			}
		}
		MAX = max(MAX, s);
	}
	res.push_back(s);
	printf("%lld\n", MAX);
	return 0;
}
