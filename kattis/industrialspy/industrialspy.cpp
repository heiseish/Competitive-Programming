/** 
Humans are suspicious and jealous creatures. When they see something perfect, they want to find a flaw.        
*/
#include <bits/stdc++.h>
#define forn(i, l, r) for(int i=l;i<=r;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define nd second
#define st first
#define sz(x) (int)x.size()
#define UNIQUE(v) (v).resize(unique(all(v)) - (v).begin())
#define mp make_pair
#define debug(x) cout<<#x<<" --> "<<x<<endl;

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
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
}  
int main() {
	sieve(1000);
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int tc;
	cin>>tc;
	string n;
	while(tc--) {
		cin>>n;
		vi a;
		for (auto &ch : n) a.pb((int) ch - '0');
		sort(all(a));
		int ans = 0;
		do {
			int cur = 0;
			for (auto &v : a) {
				cur += v;
				cur*=10;
			}
			cur/=10;
			if (isPrime(cur)) ans++;
		} while(next_permutation(all(a)));
		cout << ans<<'\n';
	}
	return 0;
}
