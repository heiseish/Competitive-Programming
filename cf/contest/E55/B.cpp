/** 
It does not do to dwell on dreams and forget to live.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl

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
string row;
int g = 0;

bool can(int m) {
	int cur = 0;
	forn(i, 0, m - 1) 
		if (row[i] == 'G')
			cur++;
	if ((cur >= m - 1 && cur < g) || (cur == g && cur == m)) return true;
	for (int i = 0; i < row.length() - m; i++) {
		int e = i + m;
		if (row[i] == 'G') cur--;
		if (row[i + m] == 'G') cur++;
		if ((cur >= m - 1 && cur < g) || (cur == g && cur == m)) return true;
	}
	return false;
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	cin >> row;
	
	forn(i, 0, row.length() - 1)
		if (row[i] == 'G')
			g++;
	int l = -1, r = row.length() + 1;
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		if (can(m)) l = m;
		else r = m;
	}
	printf("%d\n", l);
	return 0;
}
