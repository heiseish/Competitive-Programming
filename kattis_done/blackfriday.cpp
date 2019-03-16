/** 
People become stronger because they have things they cannot forget. That’s what you call growth.
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) (v.begin(),v.end())
#define pb push_back
#define nd second
#define st first

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
int d[10] = { 0 };
int idx[10] = { -1 };
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	scanf("%d", &n);
	forn(i, 0, n - 1) {
		int temp;
		scanf("%d", &temp);
		d[temp]++;
		idx[temp] = i + 1;
	}
	for(int i = 6; i >= 1; i--) {
		if (d[i] == 1) {
			printf("%d\n", idx[i]);
			exit(0);
		}
	}
	printf("none\n");
	return 0;
}
