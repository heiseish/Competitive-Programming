/** 
"You think you're the only ones who matter. You think you can put off death. But that peace made you foolish and thoughtless. If you kill someone, someone else will kill you… this hatred binds us together."
"Those who do not understand true pain can never understand true peace."

I’m the only one who can bear the full brunt of your hate! It’s my job, no one else’s! I’ll bear the burden of your hatred… and we’ll die together!

When a man learns to love, he must bear the risk of hatred.

Those in the ninja world who break the rules and regulations are called filth, but those who don't care about their companions... are even lower than filth.

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

bool can(char i) {
	return i == 'o' || i == 'u' || i == 'i'
		|| i == 'a' || i == 'e' || i == 'y';
}
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	while(scanf("%d", &t) && t) {
		int MAX = -1;
		string best = "";
		forn(i, 0, t-1) {
			string temp;
			cin >> temp;
			int cur = 0;
			forn(j, 0, temp.length() - 2) {
				if (can(temp[j]) && temp[j] == temp[j + 1]) {
					cur++;
				}
			}
			if (cur > MAX) {
				MAX = cur;
				best = temp;
			}
		}
		printf("%s\n", best.c_str());
	}
	return 0;
}
