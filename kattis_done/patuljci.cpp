/** 
In this world,where ever there is light - there are also shadows. As long as the concept of winners exists, there must also be losers. The selfish desire of wanting to maintain peace causes wars, and hatred is born to protect love.
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
const int maxn = 9;
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n[maxn];
	int s = 0;
	forn(i, 0, maxn - 1) {
		scanf("%d", &n[i]);
		s+=n[i];
	}

	forn(i, 0, maxn - 1) {
		forn(j, i + 1, maxn - 1) {
			if (s - n[i] - n[j] == 100) {
				forn(k, 0, maxn - 1) {
					if (k == i || k == j) continue;
					printf("%d\n", n[k]); 
				}
				exit(0);
			} 
		}
	}

	return 0;
}
