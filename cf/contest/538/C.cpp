/** 
you can do it too because you are not a failure like me.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define debug(x) cout<<#x<<" -> "<<x<< endl
#define kakimasu(x) cout << x << '\n'
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair

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

const int INF = 1 << 30;
/**
Start coding from here
*/


ll _sieve_size;
bitset<10000010> bs;                     // 10^7 should be enough for most cases
vll primes;               // compact list of primes in form of vector<long long>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound+1;                     // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i < _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i <= _sieve_size starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    primes.push_back(i);       // also add this vector containing list of primes
} }                                           // call this method in main method

bool isPrime(ll N) {                 // a good enough deterministic prime tester
  if (N < _sieve_size) return bs[N];                // now O(1) for small primes
  for (int i = 0; (i < primes.size()) && (primes[i]*primes[i] <= N); i++)
    if (N%primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2

// second part
unordered_map<ll, ll> g;
void primeFactors(ll N) {   // remember: vi is vector of integers, ll is long long                  // vi `primes' (generated by sieve) is optional
  ll PF_idx = 0, PF = primes[PF_idx];     // using PF = 2, 3, 4, ..., is also ok
  while ((N != 1) && (PF*PF <= N)) {   // stop at sqrt(N), but N can get smaller
    while (N%PF == 0) { N /= PF; g[PF]++; }      // remove this PF
    PF = primes[++PF_idx];                              // only consider primes!
  }
  if (N != 1) g[N]++;     // special case if N is actually a prime
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	const int tosieve = 2e6;
	sieve(tosieve);
	ll n, b;
	cin>>n>>b;
	if (isPrime(b) && n < b) {
		puts("0");
		return 0;
	}
	primeFactors(b);
	ll ans = 1LL << 60;
	for (auto &v : g) {
		ll have = 0ll;
		ll start = v.st;
		while(start <= n) {
			have += n / start;
			if ((double) n / (1.0 * v.st) >= (double) start) start *= v.st;
			else start = n + 1;
		}

		ans = min(ans, have/v.nd);
	}
	cout << ans << '\n';
	return 0;
}