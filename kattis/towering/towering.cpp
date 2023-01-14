/** 
Hard work is worthless for those that don’t believe in themselves.
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
bool ft[6] = { false };
vector<int> t(6);
int a, b;
void printFirstTower() {
	forn(i, 0, 5) {
		forn(j, i + 1, 5) {
			forn(k, j + 1, 5) {
				if (t[i] + t[j] + t[k] == a) {
					printf("%d %d %d ", t[i], t[j], t[k]);
					ft[i] = ft[j] = ft[k] = true;
					return;
				}
			}
		}
	}
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	forn(i, 0, 5) scanf("%d", &t[i]);
	
	scanf("%d %d", &a, &b);
	
	sort(t.begin(), t.end(), greater<int>());
	printFirstTower();
	forn(i, 0, 5) 
		if (!ft[i])
			printf("%d ", t[i]);
	printf("\n");
	return 0;
}
