/** 
Words are like swords. If you use them the wrong way, they can turn into ugly weapons.        
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
//need to sort first b4 using unique

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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = (ll) round(fa[i].real());
    return result;
}

const int maxn = 5e4 + 3;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	int n;
	cin>>n;
	vi a(n);
	unordered_map<int,int> track;
	int numzeros=0;
	forn(i, 0, n-1) {
		cin>>a[i];
		track[a[i]]++;
	}
	ll ans = 0LL;
	ans+=1LL * track[0] * (track[0]-1) * (track[0]-2);
	for (auto &v :  track) {
		if (v.st==0) continue;
		ans+= 2LL * track[0] * v.nd*(v.nd-1);
	}
	vi b(maxn * 2, 0), c(maxn * 2, 0);
	forn(i,0,n-1) {
		if (a[i]==0) continue;
		b[maxn + a[i]]++;
		c[maxn + a[i]]++;
	}
	vll fin=multiply(b, c);
	forn(i, 0, sz(fin)-1) {
		if (fin[i]==0) continue;
		int idx=i-2*maxn;
		if (!track[idx]) continue;
		ll tosubtract = 0LL;
		if (idx%2==0 && idx!=0) tosubtract+=track[idx/2];
		ans+=1LL * (fin[i]-tosubtract)*track[idx];
	}
	cout<<ans<<'\n';

	return 0;
}
