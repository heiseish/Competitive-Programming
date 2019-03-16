/** 
Those who cannot acknowledge themselves will eventually fail.        
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

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
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

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
	#endif
	string s, r;
	cin>>s>>r;
	int ls=sz(s), lr=sz(r);
	vector<vi> in(4), to(4);
	forn(i, 1, ls) {
		if (i <= lr) {
			if (r[i-1]=='A') in[0].pb(i);
			else if (r[i-1]=='T') in[1].pb(i);
			else if(r[i-1]=='G') in[2].pb(i);
			else in[3].pb(i);
		}
		if (s[i-1]=='A') to[0].pb(i);
		else if (s[i-1]=='T') to[1].pb(i);
		else if(s[i-1]=='G') to[2].pb(i);
		else to[3].pb(i);
	}
	unordered_map<int, int> cc;
	forn(i, 0, 3) {
		vi a(ls + 1, 0), b(ls + 1, 0);
		for (auto &n: in[i]) {
			a[n] = 1;
		}
		for (auto &n: to[i]) {
			b[ls + 1 - n] = 1;
		}
		vi c = multiply(a, b);
		for(int i = ls+1; i>=2;i--) {
			cc[ls + 1 - i]+=c[i];
		}
	}
	int best=-1;
	forn(i, 0, ls-lr) best=max(best, cc[i]);
	cout<<lr-best<<"\n";
	return 0;
}
