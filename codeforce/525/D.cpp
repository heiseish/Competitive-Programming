/** 
it is foolish to fear what we have to see and know”
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
int ans;
void ask(int c, int d) {
	printf("? %d %d\n", c, d);
	fflush(stdout);
	scanf("%d", &ans);
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int cur, maska = 0, maskb = 0;
	ask(maska, maskb);
	cur = ans;
	for (int i = 29; i>=0;i-- ) {
		if (cur == 0) {
			ask(maska | (1 << i), maskb);
			if (ans == -2) exit(0);
			int f = ans;
			ask(maska, maskb | (1 << i));
			if (ans == -2) exit(0);
			int s = ans;
			if (f < s) {
				maska |= (1 << i);
				maskb |= (1 << i);
			}
		} else  {
			ask(maska, maskb | (1 << i));
			if (ans == -2) exit(0);
			int f = ans;
			ask(maska | (1 << i), maskb );
			if (ans == -2) exit(0);
			int s = ans;
			if (f > s) {
				maska |= (1 << i);
				maskb |= (1 << i);
			} else if (f == s) {
				if (cur == 1) maska |= (1 << i);
				else if (cur == -1) maskb |= (1 << i);
				cur = f;
			}
		}
	}
	printf("! %d %d\n", maska, maskb);
	fflush(stdout);
	return 0;
}
