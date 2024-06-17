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

const ll inf = 3e9 + 7;
/**
Start coding from here
*/

ld dist(ld xA, ld yA, ld xB, ld yB) {
	return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll a, b, c;
	ll xA, yA, xB, yB;
	scanf("%lld %lld %lld", &a, &b, &c);
	scanf("%lld %lld %lld %lld", &xA, &yA, &xB, &yB);
	ld inhA, inhB, invA, invB;
	inhA = 1.0 * (-c - b * yA) / a;
	inhB = 1.0 * (-c - b * yB) / a;
	invA = 1.0 * (-c - a * xA) / b;
	invB = 1.0 * (-c - a * xB) / b;
	vector<ld> poss;
	poss.push_back(abs(xA - xB) + abs(yA - yB));
	poss.push_back(dist(xA, yA, inhA, yA) + dist(inhA, yA, inhB, yB) + dist(inhB, yB, xB, yB));
	poss.push_back(dist(xA, yA, xA, invA) + dist(xA, invA, inhB, yB) + dist(inhB, yB, xB, yB));
	poss.push_back(dist(xA, yA, inhA, yA) + dist(inhA, yA, xB, invB) + dist(xB, invB, xB, yB));
	poss.push_back(dist(xA, yA, xA, invA) + dist(xA, invA, xB, invB) + dist(xB, invB, xB, yB));
	ld MIN = 1.0L * inf;
	forn(i, 0, poss.size() - 1) {
		if (poss[i] < MIN) MIN = poss[i];
	}
	printf("%.10Lf\n", MIN);
	return 0;
}
